#include <node.h>
#include <windows.h>

namespace winBeep
{
using namespace v8;

static void WinBeep(const FunctionCallbackInfo<Value> &args)
{
  bool ok = false;
  Isolate *isolate = args.GetIsolate();
  if (args.Length() == 2)
  {
    if (!args[0]->IsNumber() || !args[1]->IsNumber())
    {
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Arguments type must be number.").ToLocalChecked()));
      return;
    }
    int frequency = args[0]->Int32Value(isolate->GetCurrentContext()).ToChecked();
    int duration = args[1]->Int32Value(isolate->GetCurrentContext()).ToChecked();
    if (frequency < 37 || frequency > 32767)
    {
      isolate->ThrowException(Exception::RangeError(String::NewFromUtf8(isolate, "Frequency must be in 37 thru 32767.").ToLocalChecked()));
      return;
    }
    if (duration <= 0)
    {
      isolate->ThrowException(Exception::RangeError(String::NewFromUtf8(isolate, "Duration must > 0.").ToLocalChecked()));
      return;
    }
    ok = Beep(frequency, duration);
    if (!ok)
    {
      isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, "Failed to beep.").ToLocalChecked()));
    }
  }
  else
  {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Incorrect number of arguments.").ToLocalChecked()));
  }
  return;
}

void init(Local<Object> exports, Local<Object> module)
{
  NODE_SET_METHOD(module, "exports", WinBeep);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace winBeep
