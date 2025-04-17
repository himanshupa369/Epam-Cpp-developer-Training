 /*========= Sleep() and Wait() ===========*/
//Sleep...

//📌 What it does :
//sleep simply pauses the current thread for a specified amount of time.
//It doesn't care about any condition or event. Just sits and waits.

//📦 Analogy :
//You say : "Wake me up in 5 minutes." You don't care what happens in those 5 minutes.

//SYNTAX::
/* 

#include <chrono>
#include <thread>

std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep 2 seconds

*/


//SLEEP IS :
//“I’m done with my timeslice, and please don’t give me another one for at least n milliseconds.” 
//The OS doesn’t even try to schedule the sleeping thread until requested time has passed.

//POINTS :
//    It will keep the lock and sleep.
//    Sleep is directly to thread, it is a thread function.

//❗ Important :
//Doesn’t release locks.
//CPU might schedule other threads during the sleep.
//Used for delays, timing, or testing.


//WAIT IS :

//📌 What it does :
//wait blocks the thread until a specific condition is met, usually involving a condition variable.
//It’s used for thread synchronization.

//📦 Analogy :
//You say : "Wake me up when dinner is ready." You're waiting for an event, not just time.

//SYNTAX::
/* 
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });  // waits until ready is true
    // continue work
}

*/

//“I’m done with my timeslice.Don’t give me another timeslice until someone calls notify().”
//As with sleep(), the OS won’t even try to schedule your task unless someone calls notify() (or one of a few other wakeup scenarios occurs).

//POINTS :
//    It releases the lock and wait.
//    Wait is on condition variable, it is like there is a condition variable in a thread and wait is applied to that CV but it ends up putting thread in waiting state.

//❗ Important :
//Releases the lock while waiting.
//Reacquires it when resumed.
//Used for synchronizing threads based on shared state.
