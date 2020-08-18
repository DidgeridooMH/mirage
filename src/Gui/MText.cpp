#include <Gui/MText.hpp>
#include <iostream>

MText::MText(const std::wstring& text, int x, int y) : m_text(text) {
  HDC wdc = GetWindowDC(nullptr);
  SIZE textSize;
  GetTextExtentPointW(wdc, m_text.c_str(), m_text.length(), &textSize);
  m_width = textSize.cx;
  m_height = textSize.cy;

  m_offsetX = x;
  m_offsetY = y;
}

void MText::Draw(int offsetX, int offsetY) {
#ifdef _WIN64
  HWND hwnd = m_parent->GetHandle();
  HDC wdc = GetWindowDC(hwnd);

  RECT parentRect = {offsetX, offsetY, 0, 0};

  parentRect.left += m_offsetX;
  parentRect.top += m_offsetY;

  SetTextColor(wdc, RGB(0, 0, 0));
  SetBkMode(wdc, TRANSPARENT);
  SetBkColor(wdc, RGB(0, 0, 0));

  DrawText(wdc, m_text.c_str(), -1, &parentRect, DT_SINGLELINE | DT_NOCLIP);

  DeleteDC(wdc);
#endif
}

void MText::SetText(const std::wstring& text) {
  m_text = text;
  Update();
}

#ifdef _WIN64
HWND MText::GetHandle() { return NULL; }
#endif
