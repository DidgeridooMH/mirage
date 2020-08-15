#include <Core/MApp.hpp>
#include <Gui/Windows/MWinWindows.hpp>

std::mutex MApp::m_instanceMutex;
MApp* MApp::p_instance;

#ifdef _WIN64
MApp::MApp() {
  WNDCLASS wc = {};

  wc.lpfnWndProc = &MWinWindow::ProcessMessage;
  wc.hInstance = GetWinInstance();
  wc.lpszClassName = GetWinClassName();

  RegisterClass(&wc);
}

MApp* MApp::GetInstance() {
  if (p_instance == nullptr) {
    std::lock_guard<std::mutex> lock(m_instanceMutex);
    if (p_instance == nullptr) {
      p_instance = new MApp();
    }
  }
  return p_instance;
}

HINSTANCE MApp::GetWinInstance() { return GetModuleHandle(NULL); }

const wchar_t* MApp::GetWinClassName() { return L"Mirage Default Window"; }
#endif
