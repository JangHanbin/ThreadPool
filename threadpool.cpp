#include "threadpool.h"

int ThreadPool::num_of_thread_pool_class_ = 0;


int ThreadPool::get_num_of_thread() const
{
    return num_of_thread_;
}

void ThreadPool::set_num_of_thread(int num_of_thread)
{
    num_of_thread_ = num_of_thread;
}

void ThreadPool::set_num_of_thread(const char *num_of_thread)
{
    num_of_thread_ = atoi(num_of_thread);
}

int ThreadPool::get_num_of_thread_pool_class() const
{
    return ThreadPool::num_of_thread_pool_class_;
}

bool ThreadPool::initPool()
{
    if(num_of_thread_ > 0)
    {
        pool.reserve(num_of_thread_);
        return true;
    }

    std::cout<<"Num of Thread must be up to 0."<<std::endl;
    std::cout<<"Current Num of Thread Value : "<<num_of_thread_<<std::endl;
    return false;
}

bool ThreadPool::jmpToPool(void (*fp))
{
    pool.push_back(fp);
}

ThreadPool::ThreadPool()
{
    init_count_door.lock();
    ThreadPool::num_of_thread_pool_class_++;
    init_count_door.unlock();
}

ThreadPool::ThreadPool(int num)
{
    init_count_door.lock();
    ThreadPool::num_of_thread_pool_class_++;
    init_count_door.unlock();
    num_of_thread_ = num;
}

ThreadPool::ThreadPool(const char *num)
{
    init_count_door.lock();
    ThreadPool::num_of_thread_pool_class_++;
    init_count_door.unlock();
    num_of_thread_ = atoi(num);
}

ThreadPool::~ThreadPool()
{
    ThreadPool::num_of_thread_pool_class_--;
}

int ThreadPool::get_num_of_activated_thread() const
{
    return num_of_activated_thread_;
}

void ThreadPool::inc_num_of_activated_thread()
{
    num_of_activated_thread_++;
}
