#ifndef _MIRAGE_MCLICKEVENTHANDLER_HPP_
#define _MIRAGE_MCLICKEVENTHANDLER_HPP_

#include <Events/MEventHandler.hpp>

class MDrawable;

typedef void (*ClickEventHandler)(MDrawable* ref, int x, int y, int rx, int ry);

class MClickEventHandler : MEventHandler {
 public:
  MClickEventHandler(ClickEventHandler handler);

  void Fire(MDrawable* ref, int x, int y, int rx, int ry);

 private:
  ClickEventHandler m_handler;
};

#endif
