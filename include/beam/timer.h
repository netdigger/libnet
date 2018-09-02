/* Copyright ©2018 All right reserved, Author: netdigger*/

#ifndef __TIMER_H__
#define __TIMER_H__
namespace beam {
class Task;
class Timer {
   public:
    virtual ~Timer(){};

    enum Status { kWaiting = 1, kRunning, kStopped };

    virtual Status Stop() = 0;

    static Timer* DoOnce(Task&, void*, int);
    static Timer* DoRepeat(Task&, void*, int);
};
}  // namespace beam
#endif