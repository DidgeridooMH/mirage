#include <Core/Mirage.hpp>
#include <Gui/MWindow.hpp>
#include <memory>

int wmain(int argc, wchar_t** argv, wchar_t** env) {
  MApp::GetInstance();

  auto window = std::make_shared<MWindow>();
  window->Show();

  while (window->HandleWindowMessage())
    ;

  return 0;
}