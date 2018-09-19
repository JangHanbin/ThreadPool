#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <vector>
#include <thread>

class ThreadBody
{
    // 1 = running
    // 2 = waiting
    bool status_=0;
    std::thread worker;

public:
    ThreadBody();
    bool get_status() const;
    void switch_status();
};

class ThreadPool
{
    //For Number of Thread in Thread Pool
    int num_of_thread_ = 0;
    //For counting active thread
    int num_of_activated_thread_ = 0;

    std::vector<ThreadBody *> pool;
    std::mutex init_count_door;
    std::mutex thread_door;

public:
    ThreadPool();
    ThreadPool(int num);
    ThreadPool(const char* num);
    ~ThreadPool();

    //For counting thread pool class
    static int num_of_thread_pool_class_;

    void inc_num_of_activated_thread();
    int get_num_of_activated_thread() const;
    int get_num_of_thread() const;
    void set_num_of_thread(int num_of_thread);
    void set_num_of_thread(const char* num_of_thread);
    int get_num_of_thread_pool_class() const;

    bool initPool();
    bool jmpToPool(void(*fptr) (void), ...);
};

#endif // THREADPOOL_H
