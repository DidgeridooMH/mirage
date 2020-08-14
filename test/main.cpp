#include <Gui/MWindow.hpp>
#include <memory>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int) {
  MApp::GetInstance(hInstance);

  auto window = std::make_shared<MWindow>();
  window->Show();

  while (MWindow::HandleMessage())
    ;

  return 0;
}