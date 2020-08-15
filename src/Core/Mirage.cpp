#include <Mirage.hpp>
#include <stdexcept>

#ifdef _WIN64

#include <windows.h>

#ifdef main
#undef main
#endif

#ifdef wmain
#undef wmain
#endif

int main(int argc, char** argv) { return MMain(argc, argv); }

int wmain(int argc, wchar_t** argv, wchar_t** env) {
  return MMainW(argc, argv, env);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  return MMain(__argc, __argv);
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int) {
  return MMainW(__argc, __wargv, _wenviron);
}

#endif