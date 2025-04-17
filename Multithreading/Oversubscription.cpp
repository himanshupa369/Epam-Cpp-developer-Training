// What is OverSubscription in multithreading ?

//Oversubscription in multithreading happens when you create more threads than the number of CPU cores available to run them.

//🔄 Example :
//Imagine you have a CPU with 4 cores, but your program creates 100 threads.
//
//➡️ Only 4 threads can run simultaneously.
//➡️ The rest have to wait and the OS context - switches between them.

//⚠️ What’s the problem with oversubscription?
//Issue                              | Explanation
//🌀 Context Switching Overhead      | The OS keeps switching between threads.This adds CPU overhead and slows everything down.
//🔄 Cache Thrashing                 | Switching threads can cause frequent cache invalidation, reducing CPU efficiency.
//🧠 Memory Usage                    | Each thread uses stack space.Too many threads = more memory consumption.
//😵‍💫 Poor Performance                | Instead of speeding up your program, it may become slower or unstable.

//✅ When is it OK ?
//For I / O - bound tasks(like waiting for network or file I / O), having more threads than cores can still make sense.
//But for CPU - bound tasks, try to match threads to core count(or use thread pools).

//Oversubscription = Too many threads chasing too few cores.
//Result = More switching, less working.
