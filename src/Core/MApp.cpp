#include <Core/MApp.hpp>

CallbackMap MApp::m_updateCallbacks;
std::mutex MApp::m_instanceMutex;
MApp* MApp::p_instance;

#ifdef _WIN64
MApp::MApp() {
  WNDCLASS wc = {};

  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.lpfnWndProc = &MApp::ProcessMessage;
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

int MApp::Execute() {
#ifdef _WIN64
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.lParam;
#endif
}

HINSTANCE MApp::GetWinInstance() { return GetModuleHandle(NULL); }

const wchar_t* MApp::GetWinClassName() { return L"Mirage Default Window"; }

void MApp::RegisterComponent(void* component, UpdateCallback callback) {
  m_updateCallbacks.insert(std::make_pair(component, callback));
}

void MApp::DeregisterComponent(void* component) {
  m_updateCallbacks.erase(component);
}

LRESULT CALLBACK MApp::ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                      LPARAM lParam) {
  auto _this =
      reinterpret_cast<MDrawable*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

  if (m_updateCallbacks.count(_this) > 0) {
    return m_updateCallbacks[_this](_this, hwnd, uMsg, wParam, lParam);
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#endif
