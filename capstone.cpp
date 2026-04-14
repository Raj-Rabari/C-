#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

class ITask
{
public:
    virtual ~ITask() = default; // Virtual destructor for proper cleanup of derived classes, if derived class is deleted using a base class pointer then the destructor of the derived class will be called, ensuring proper resource management.

    virtual void execute(const std::string &taskName) = 0;
};

class FrontendTask : public ITask
{
    std::string clientName;

public:
    FrontendTask(std::string name) : clientName(std::move(name)) {}

    void execute(const std::string &workerName) override
    {
        std::cout << "[work]" << workerName << " is building UI for " << clientName << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
};

class DevopsTask : public ITask
{
    std::string serverIp;

public:
    DevopsTask(std::string ip) : serverIp(std::move(ip)) {}

    void execute(const std::string &workerName) override
    {
        std::cout << "[work]" << workerName << " is setuping EC2 at" << serverIp << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
};

class AiTask : public ITask
{
    std::string modelName;

public:
    AiTask(std::string name) : modelName(std::move(name)) {}

    void execute(const std::string &workerName) override
    {
        std::cout << "[work]" << workerName << " is training " << modelName << " model" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    }
};

class AgencyQueue
{
private:
    std::queue<std::unique_ptr<ITask>> jobs;
    std::mutex mtx;
    std::condition_variable cv;
    bool isShuttingDown = false;

public:
    void addJob(std::unique_ptr<ITask> job)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            jobs.push(std::move(job));
            std::cout << "[addJob] Job added to the queue. Total jobs: " << jobs.size() << std::endl;
        }
        cv.notify_one();
    }

    std::unique_ptr<ITask> popJob()
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this]
                { return !jobs.empty() || isShuttingDown; });

        if (isShuttingDown && jobs.empty())
        {
            return nullptr;
        }

        std::unique_ptr<ITask> job = std::move(jobs.front());
        jobs.pop();
        return job;
    }

    void shutdown()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            isShuttingDown = true;
        }
        cv.notify_all();
    }
};

void engineerRoutine(std::string name, AgencyQueue &queue)
{
    while (true)
    {
        std::unique_ptr<ITask> job = queue.popJob();

        if (job == nullptr)
        {
            std::cout << "[engineerRoutine] " << name << "has no task & is shutting down." << std::endl;
            break;
        }

        job->execute(name);
    }
}

int main()
{
    std::cout << "=== STARTING MICRO-AGENCY ENGINE ===\n\n";

    AgencyQueue taskQueue;
    std::vector<std::thread> team;

    // 1. Spawn the workers (Pass the queue safely by Reference)
    team.push_back(std::thread(engineerRoutine, "Raj", std::ref(taskQueue)));
    team.push_back(std::thread(engineerRoutine, "Satpal", std::ref(taskQueue)));
    team.push_back(std::thread(engineerRoutine, "Aadarsh", std::ref(taskQueue)));

    // Let the workers boot up
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "\n[System] Inbound Client Requests...\n";

    // 2. Add jobs to the queue (Main thread acts as the dispatcher)
    taskQueue.addJob(std::make_unique<FrontendTask>("E-Commerce Store"));
    taskQueue.addJob(std::make_unique<DevopsTask>("192.168.1.50"));
    taskQueue.addJob(std::make_unique<AiTask>("ScriptWeaver V2"));
    taskQueue.addJob(std::make_unique<FrontendTask>("Portfolio Website"));
    taskQueue.addJob(std::make_unique<DevopsTask>("10.0.0.2"));

    // Give them time to finish the work
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 3. Graceful Shutdown
    std::cout << "\n[System] Initiating Server Shutdown...\n";
    taskQueue.shutdown();

    // 4. Join all threads
    for (std::thread &engineer : team)
    {
        engineer.join();
    }

    std::cout << "\n=== ENGINE OFFLINE (Zero Memory Leaks) ===\n";
    return 0;
}