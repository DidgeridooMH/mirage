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

  static MApp* GetInstance();

#ifdef _WIN64
  static HINSTANCE GetWinInstance();
  static const wchar_t* GetWinClassName();
#endif

 protected:
  MApp();

 private:
  static std::mutex m_instanceMutex;
  static MApp* p_instance;
};

#endif
