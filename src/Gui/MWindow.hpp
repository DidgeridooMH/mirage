#ifndef _MIRAGE_MWINDOW_HPP_
#define _MIRAGE_MWINDOW_HPP_

#include <Core/MApp.hpp>
#include <thread>

class MWindowBase {
 public:
  MWindowBase(MWindowBase* parent = nullptr);

  virtual void Show() = 0;
  virtual bool HandleWindowMessage() = 0;

 private:
  MWindowBase* m_parent;
};

#endif
