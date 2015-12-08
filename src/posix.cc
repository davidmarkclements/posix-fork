#include <node.h>
#include <unistd.h>
#include <nan.h>

NAN_METHOD(Fork);
NAN_METHOD(Daemon);
NAN_METHOD(Getpid);

NAN_METHOD(Fork) {
  info.GetReturnValue().Set(fork());
}

NAN_METHOD(Daemon) { 
  info.GetReturnValue().Set(daemon(info[0]->IsTrue() ? 0 : -1, info[1]->IsTrue() ? 0 : -1)); 
}

NAN_METHOD(Getpid) {
  info.GetReturnValue().Set(getpid());
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT(target, Fork);
  NAN_EXPORT(target, Daemon);
  NAN_EXPORT(target, Getpid);
}

