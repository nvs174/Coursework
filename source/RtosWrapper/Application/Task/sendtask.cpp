#include "sendtask.h"

void SendTask::Execute() 
{
  for (;;) 
  {
    mTransfer.TransferData();
    Sleep(1000ms);
  }
}
