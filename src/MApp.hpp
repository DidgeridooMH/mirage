#ifndef MIRAGE_HPP
#define MIRAGE_HPP

#ifdef _WIN64

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#endif

#include <mutex>

class MApp {
 public:
  MApp(MApp& other) = delete;
  void operator=(const MApp&) = delete;

#ifdef _WIN64
  static MApp* GetInstance(HINSTANCE hInstance = nullptr);
  static HINSTANCE GetWinInstance();
  static const wchar_t* GetWinClassName();
#endif

 protected:
#ifdef _WIN64
  MApp(HINSTANCE hInstance);
#endif

 private:
  static std::mutex m_instanceMutex;
  static MApp* p_instance;

#ifdef _WIN64
  static HINSTANCE m_hInstance;
#endif
};

#endif
