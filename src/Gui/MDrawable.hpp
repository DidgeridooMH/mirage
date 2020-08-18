#ifndef _MIRAGE_MDRAWABLE_HPP_
#define _MIRAGE_MDRAWABLE_HPP_

#include <Core/MApp.hpp>
#include <Events/MClickEventHandler.hpp>
#include <memory>
#include <set>
#include <vector>

class MDrawable {
 public:
  virtual ~MDrawable() = default;

  virtual void Draw(int offsetX, int offsetY) = 0;

  void Update();

#ifdef _WIN64
  virtual HWND GetHandle() = 0;
#endif

  void Attach(std::shared_ptr<MDrawable> drawable);

  void HandleClick(int x, int y, int rx, int ry);

  void SetOffset(int x, int y);
  int GetXOffset() const;
  int GetYOffset() const;

  int GetWidth() const;
  int GetHeight() const;

  void RegisterClickHandler(ClickEventHandler eventHandler);
  // TODO: Deregistering will need an event class. Purhaps template it to take
  // the function pointer type.

 protected:
  void SetParent(MDrawable* parent);

  std::vector<std::shared_ptr<MDrawable>> m_children;
  MDrawable* m_parent;

  int m_offsetX;
  int m_offsetY;
  int m_width;
  int m_height;

  std::set<std::shared_ptr<MClickEventHandler>> m_clickEvents;
};

#endif
