#include <Gui/MWindow.hpp>
#include <MApp.hpp>

std::mutex MApp::m_instanceMutex;
MApp* MApp::p_instance;

#ifdef _WIN64
HINSTANCE MApp::m_hInstance;

MApp::MApp(HINSTANCE hInstance) {
  m_hInstance = hInstance;

  WNDCLASS wc = {};

  wc.lpfnWndProc = &MWindow::ProcessMessage;
  wc.hInstance = hInstance;
  wc.lpszClassName = GetWinClassName();

  RegisterClass(&wc);
}

MApp* MApp::GetInstance(HINSTANCE hInstance) {
  if (p_instance == nullptr) {
    std::lock_guard<std::mutex> lock(m_instanceMutex);
    if (p_instance == nullptr) {
      p_instance = new MApp(hInstance);
    }
  }
  return p_instance;
}

HINSTANCE MApp::GetWinInstance() { return m_hInstance; }

const wchar_t* MApp::GetWinClassName() { return L"Mirage Default Window"; }
#endif
