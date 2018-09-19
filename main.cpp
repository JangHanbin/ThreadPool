#include <iostream>
#include <glog/logging.h>
#include "threadpool.h"

using namespace std;

void usage(){ cout<<"./ThreadPoolTest <NumOfThread>"<<endl;}

int sum(int a, int b, int c)
{
    return a+b+c;
}

int sum(int a, int b, int c, int d)
{
    return a + b + c + d;
}
int main(int argc, char*argv[])
{
    //argument count check.
    if(argc!=2)
    {
        usage();
        exit(1);
    }

    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);

    google::LogToStderr();
//    TODO remove comment when this code published
//    google::SetLogDestination(google::GLOG_INFO, "./glog");

    //Init ThreadPool
    ThreadPool threadPool;
    //Set Number of Thread in pool
    threadPool.set_num_of_thread(argv[1]);

    DLOG(INFO)<<"Number of Thread : " << threadPool.get_num_of_thread()<<endl;
    DLOG(INFO)<<"Number of Thread pool class : " << threadPool.get_num_of_thread_pool_class()<<endl;

    //if failed to make pool
    if(!threadPool.initPool())
        exit(1);


    //TODO : This call what I want to make.
    threadPool.jmpToPool(sum,1,2,3);
    threadPool.jmpToPool(sum,1,2,3,4);



    return 0;
}
