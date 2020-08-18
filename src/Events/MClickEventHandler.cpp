#include <Events/MClickEventHandler.hpp>

MClickEventHandler::MClickEventHandler(ClickEventHandler handler)
    : m_handler(handler) {
  m_type = EventType::ClickEvent;
}

void MClickEventHandler::Fire(MDrawable* ref, int x, int y, int rx, int ry) {
  m_handler(ref, x, y, rx, ry);
}
