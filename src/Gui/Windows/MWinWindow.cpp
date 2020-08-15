#include <Gui/MWindow.hpp>
#include <stdexcept>

#ifdef _WIN64
MWinWindow::MWinWindow(MWinWindow* parent) {
  m_parent = parent;
  m_hwnd = CreateWindowEx(0, MApp::GetWinClassName(), L"Mirage App",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
                          MApp::GetWinInstance(), NULL);
  if (m_hwnd == NULL) {
    throw std::runtime_error("Unable to create window");
  }
}

MWinWindow::~MWinWindow() {}

void MWinWindow::Show() { ShowWindow(m_hwnd, 1); }

bool MWinWindow::HandleWindowMessage() {
  MSG msg = {};
  bool messageReceived = GetMessage(&msg, NULL, 0, 0);
  if (messageReceived) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return messageReceived;
}

LRESULT CALLBACK MWinWindow::ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                            LPARAM lParam) {
  auto _this = reinterpret_cast<MWinWindow*>(lParam);

  switch (uMsg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif
