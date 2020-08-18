#ifndef _MIRAGE_MWINDOW_HPP_
#define _MIRAGE_MWINDOW_HPP_

#include <Gui/MDrawable.hpp>
#include <thread>

class MWindowBase : public MDrawable {
 public:
  virtual ~MWindowBase() = default;

  virtual void Show() = 0;
};

#ifdef _WIN64
#include <Gui/Windows/MWinWindow.hpp>
#endif

#endif
