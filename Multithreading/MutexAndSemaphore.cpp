//**** Mutex and Semaphore ****//

//Feature*********************** | Mutex ******************************************************************************* | Semaphore **************************************************//
//Definition                     | Mutual exclusion object that allows only one thread to access a resource.             | Signaling mechanism that can allow one or more threads to access.
//Counter                        | Binary(locked / unlocked → 0 or 1)                                                    | Integer counter(can be > 1)
//Ownership                      | Only the thread that locked it can unlock it                                          | No ownership – any thread can signal(release)
//Usage                          | Used for mutual exclusion                                                             | Used for synchronization and signaling
//Thread Safety                  | Thread that doesn't own the mutex cannot unlock it                                    | Any thread can call wait() or signal()
//Deadlock Risk                  | Higher risk if not handled properly                                                   | Less prone but still possible(e.g., with wrong signal / wait use)
//Type                           | Mostly binary(1 resource)                                                             | Can be binary or counting
//Typical Use Case               | Protecting critical sections                                                          | Controlling access to a limited pool of resources
//Example in C++                 | std::mutex, std::lock_guard                                                           | std::counting_semaphore(C++20), POSIX semaphores

//    M                            S
//1)one thread               multiple thread
//2)locked/unlocked          count
//3)locking mechanism        signaling mechanism
//4)Primarly use for ME      they have pool of resources
