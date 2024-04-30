#ifndef SENDTASK
#define SENDTASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "itransfer.h" // for update value USART

class SendTask: public OsWrapper::Thread<128> 
{
public:
  SendTask(ITransfer& transfer) : mTransfer(transfer) {}
  void Execute() override 
  {
    for (;;) 
    {
      mTransfer.TransferData();
      Sleep(1000ms);
    }
  }
private:
ITransfer& mTransfer;
};

#endif