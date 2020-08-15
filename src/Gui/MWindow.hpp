#ifndef _MIRAGE_MWINDOW_HPP_
#define _MIRAGE_MWINDOW_HPP_

#include <Core/MApp.hpp>
#include <thread>

class MWindowBase {
 public:
  virtual ~MWindowBase() = default;

  virtual void Show() = 0;
  virtual bool HandleWindowMessage() = 0;

 protected:
  MWindowBase* m_parent;
};

#ifdef _WIN64
#include <Gui/Windows/MWinWindow.hpp>
#endif

#endif
