#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iosfwd>
#include <string>
#include "IMessage.h"

class Message : public IMessage{
public:
  Message(const char* m);
  virtual void ShowMsg();
  virtual void SetStr(const char* m);
  virtual const char* GetStr();

private:
  const char* message_;
};

#endif     //_MESSAGE_H_
