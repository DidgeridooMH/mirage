#ifndef _MIRAGE_MWINDOW_HPP_
#define _MIRAGE_MWINDOW_HPP_

#include <Core/MApp.hpp>
#include <thread>

class MWindow {
 public:
  MWindow(MWindow* parent = nullptr);

  void Show();

  static LRESULT CALLBACK ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                         LPARAM lParam);

  static bool HandleMessage();

 private:
  MWindow* m_parent;
  HWND m_hwnd;
  std::thread m_messageThread;
};

#endif
