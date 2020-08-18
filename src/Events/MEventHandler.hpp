#ifndef _MIRAGE_EVENT_HANDLER_HPP_
#define _MIRAGE_EVENT_HANDLER_HPP_

enum class EventType { ClickEvent };

class MEventHandler {
 public:
  EventType GetType() const;

 protected:
  EventType m_type;
};

#endif
