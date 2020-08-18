#ifndef _MIRAGE_MIRAGE_HPP_
#define _MIRAGE_MIRAGE_HPP_

// Windows needs to have WinMain defined instead of main.
#ifdef _WIN64

#include <Platforms/Windows.hpp>

extern int MMainW(int argc, wchar_t** argv, wchar_t** env);

int wmain(int argc, wchar_t** argv, wchar_t** env) {
  return MMainW(argc, argv, env);
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
  return MMainW(__argc, __wargv, _wenviron);
}

#define wmain MMainW

#endif

#endif
