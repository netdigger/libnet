/* Copyright ©2018 All right reserved, Author: netdigger*/

#ifndef __TIMER_MANAGER_H__
#define __TIMER_MANAGER_H__

#include <signal.h>
#include <time.h>
#include <set>
#include "beam/mutex.h"
#include "beam/timer.h"

namespace beam {
class TimerWorker;
class TimerManager {
   public:
    static Timer* Add(Task& task, void* args, int time, bool once) {
        return instance_.DoAdd(task, args, time, once);
    };

    static void Schedule() { instance_.DoSchedule(); };

   private:
    static TimerManager instance_;
    struct TimerInfo {
        TimerWorker* worker;
        int time;
        bool operator<(const TimerInfo& info) const {
            return this->time < info.time;
        }
    };

    Mutex mutex_;
    std::set<TimerInfo> workers_;

    // timer_t timer_;
    // struct sigevent sigevent_;
    Timer* DoAdd(Task&, void*, int, bool);
    void DoSchedule();
};
}  // namespace beam
#endif