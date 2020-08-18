#include <Gui/MText.hpp>
#include <Gui/MWindow.hpp>
#include <Mirage.hpp>
#include <memory>

void testHandler(MDrawable* ref, int x, int y, int rx, int ry) {
  MessageBox(ref->GetHandle(), L"Click event", L"Event", MB_OK);
}

int wmain(int argc, wchar_t** argv, wchar_t** env) {
  auto app = MApp::GetInstance();

  auto window = std::make_shared<MWindow>();
  window->Show();

  auto text = std::make_shared<MText>(L"Text Test I");
  text->RegisterClickHandler(testHandler);
  window->Attach(text);

  return app->Execute();
}
