#include <Gui/MDrawable.hpp>
#include <iostream>

void MDrawable::Attach(std::shared_ptr<MDrawable> drawable) {
  drawable->SetParent(this);
  m_children.push_back(drawable);
}

void MDrawable::Update() {
  if (m_parent != nullptr) {
    m_parent->Update();
  } else {
    Draw(m_offsetX, m_offsetY);
  }
}

void MDrawable::SetOffset(int x, int y) {
  m_offsetX = x;
  m_offsetY = y;

  Update();
}

void MDrawable::SetParent(MDrawable* parent) { m_parent = parent; }

int MDrawable::GetXOffset() const { return m_offsetX; }

int MDrawable::GetYOffset() const { return m_offsetY; }

int MDrawable::GetWidth() const { return m_width; }

int MDrawable::GetHeight() const { return m_height; }

void MDrawable::RegisterClickHandler(ClickEventHandler eventHandler) {
  m_clickEvents.insert(std::make_shared<MClickEventHandler>(eventHandler));
}

void MDrawable::HandleClick(int x, int y, int rx, int ry) {
  for (const auto& event : m_clickEvents) {
    reinterpret_cast<MClickEventHandler*>(event.get())
        ->Fire(this, x, y, rx, ry);
  }

  for (const auto& child : m_children) {
    int cx = child->GetXOffset();
    int cy = child->GetYOffset();
    int cw = child->GetWidth();
    int ch = child->GetHeight();

    if (x >= cx && x <= (cx + cw + 10) && y >= cy && y <= (cy + ch + 10)) {
      child->HandleClick(x, y, rx - cx, ry - cy);
    }
  }
}
