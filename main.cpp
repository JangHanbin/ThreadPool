#include <iostream>
#include <glog/logging.h>
#include "threadpool.h"

using namespace std;

void usage(){ cout<<"./ThreadPoolTest <NumOfThread>"<<endl;}

int main(int argc, char*argv[])
{
    if(argc!=2)
    {
        usage();
        exit(1);
    }
    // Initialize Google's logging library.
    google::InitGoogleLogging(argv[0]);

    google::LogToStderr();
//    TODO remove comment when publish this code
//    google::SetLogDestination(google::GLOG_INFO, "./glog");

    //Init ThreadPool
    ThreadPool threadPool;
    //Set Number of Thread in pool
    threadPool.set_num_of_thread(argv[1]);

    cout<<threadPool.get_num_of_thread()<<endl;
    cout<<threadPool.get_num_of_thread_pool_class()<<endl;

    //if failed to make pool
    if(!threadPool.initPool())
        exit(1);




    return 0;
}
