#ifndef _MIRAGE_MIRAGE_HPP_
#define _MIRAGE_MIRAGE_HPP_

// Windows needs to have WinMain defined instead of main.
#ifdef _WIN64

#if defined(UNICODE) || defined(_UNICODE)
#define wmain MMainW
#else
#define main MMain
#endif

extern int MMain(int argc, char** argv);
extern int MMainW(int argc, wchar_t** argv, wchar_t** env);

#endif

#endif
