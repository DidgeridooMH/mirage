#include <Gui/MWindow.hpp>
#include <iostream>
#include <stdexcept>

#ifdef _WIN64
MWinWindow::MWinWindow(std::shared_ptr<MWinWindow> parent) {
  m_parent = parent;
  m_hwnd = CreateWindowEx(0, MApp::GetWinClassName(), L"Mirage App",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr,
                          MApp::GetWinInstance(), nullptr);
  if (m_hwnd == nullptr) {
    throw std::runtime_error("Unable to create window");
  }

  SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR)this);

  RECT windowRect;
  RECT clientRect;
  GetWindowRect(m_hwnd, &windowRect);
  GetClientRect(m_hwnd, &clientRect);

  int windowWidth = windowRect.right - windowRect.left;
  int windowHeight = windowRect.bottom - windowRect.top;
  m_width = clientRect.right - clientRect.left;
  m_height = clientRect.bottom - clientRect.top;

  m_offsetX = (windowWidth - m_width) / 2;
  m_offsetY = windowHeight - m_height;

  MApp::RegisterComponent(
      this,
      [](MDrawable* obj, HWND hwnd, UINT uMsg, WPARAM wParam,
         LPARAM lParam) -> LRESULT {
        return reinterpret_cast<MWinWindow*>(obj)->ProcessMessage(
            hwnd, uMsg, wParam, lParam);
      });
}

MWinWindow::~MWinWindow() { MApp::DeregisterComponent(this); }

void MWinWindow::Show() { ShowWindow(m_hwnd, 1); }

// TODO: Potential bottleneck. Basically it should only update the spot that
// changed. This will be easier to implement whenever, a bounding box/event
// system has been implemented.
void MWinWindow::Draw(int offsetX, int offsetY) {
  HDC hdc = GetWindowDC(m_hwnd);

  RECT rect;
  GetClientRect(m_hwnd, &rect);

  FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
  for (auto& child : m_children) {
    child->Draw(offsetX, offsetY);
  }
}

HWND MWinWindow::GetHandle() { return m_hwnd; }

#ifdef _WIN64
LRESULT MWinWindow::ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                   LPARAM lParam) {
  switch (uMsg) {
    case WM_LBUTTONDOWN:
      HandleClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
                  GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
      break;
    case WM_PAINT:
      Draw(m_offsetX, m_offsetY);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif

#endif
