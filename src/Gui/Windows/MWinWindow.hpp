#ifndef _MIRAGE_MWINWINDOWS_HPP_
#define _MIRAGE_MWINWINDOWS_HPP_

#include <Gui/MWindow.hpp>

#ifdef _WIN64
#include <windows.h>

#define MWindow MWinWindow

class MWinWindow : public MWindowBase {
 public:
  MWinWindow(MWinWindow* parent = nullptr);
  ~MWinWindow() override;

  void Show() override;
  bool HandleWindowMessage() override;

  static LRESULT CALLBACK ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                         LPARAM lParam);

 private:
  HWND m_hwnd;
};
#endif

#endif
