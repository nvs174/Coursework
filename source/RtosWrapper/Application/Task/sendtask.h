#ifndef SENDTASK
#define SENDTASK

#include "thread.hpp" // for OsWrapper::Thread<>
#include "itransfer.h" // for update register

class SendTask: public OsWrapper::Thread<512> 
{
public:
  SendTask(ITransfer& transfer) : mTransfer(transfer) {}
  void Execute() override;
private:
ITransfer& mTransfer;
};

#endif