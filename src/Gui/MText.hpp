#ifndef _MIRAGE_MTEXT_HPP_
#define _MIRAGE_MTEXT_HPP_

#include <Gui/MDrawable.hpp>
#include <string>

class MText : public MDrawable {
 public:
  MText(const std::wstring& text, int x = 0, int y = 0);

  void Draw(int offsetX, int offsetY) override;

  void SetText(const std::wstring& text);

#ifdef _WIN64
  HWND GetHandle() override;
#endif

 private:
  std::wstring m_text;
};

#endif
