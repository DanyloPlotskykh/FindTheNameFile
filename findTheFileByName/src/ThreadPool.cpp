#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int numThr) : stop(false)
{
    for (size_t i = 0; i < numThr; i++)
    {
        threads.emplace_back([this]
                             {
                while (true)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(qMutex);
                        cond.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                        {
                            return;
                        }

                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                } });
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(qMutex);
        stop = true;
    }
    cond.notify_all();

    for (std::thread &worker : threads)
    {
        worker.join();
    }
}

void ThreadPool::stoped()
{
    {
        std::unique_lock<std::mutex> lock(qMutex);
        stop = true;
    }
    cond.notify_all();
    exit(0);
}
