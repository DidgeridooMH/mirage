#ifndef _MIRAGE_MAPP_HPP_
#define _MIRAGE_MAPP_HPP_

#include <Platforms/Platform.hpp>
#include <map>
#include <mutex>

class MDrawable;

#ifdef _WIN64
typedef LRESULT (*UpdateCallback)(MDrawable*, HWND, UINT, WPARAM, LPARAM);
#endif

typedef std::map<void*, UpdateCallback> CallbackMap;

class MApp {
 public:
  MApp(MApp& other) = delete;
  void operator=(const MApp&) = delete;

  static MApp* GetInstance();

  static int Execute();

#ifdef _WIN64
  static HINSTANCE GetWinInstance();
  static const wchar_t* GetWinClassName();
  static LRESULT CALLBACK ProcessMessage(HWND hwnd, UINT uMsg, WPARAM wParam,
                                         LPARAM lParam);
#endif

  static void RegisterComponent(void* component, UpdateCallback callback);
  static void DeregisterComponent(void* component);

 protected:
  MApp();

 private:
  static std::mutex m_instanceMutex;
  static MApp* p_instance;
  static CallbackMap m_updateCallbacks;
};

#endif
