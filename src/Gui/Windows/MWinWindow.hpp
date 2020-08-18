#ifndef _MIRAGE_MWINWINDOWS_HPP_
#define _MIRAGE_MWINWINDOWS_HPP_

#include <Gui/MWindow.hpp>

#ifdef _WIN64

#define MWindow MWinWindow

class MWinWindow : public MWindowBase {
 public:
  MWinWindow(std::shared_ptr<MWinWindow> parent = nullptr);
  ~MWinWindow() override;

  void Show() override;

  void Draw(int offsetX, int offsetY) override;

  HWND GetHandle() override;

 private:
  LRESULT ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

  std::shared_ptr<MWinWindow> m_parent;
  HWND m_hwnd;
};
#endif

#endif
