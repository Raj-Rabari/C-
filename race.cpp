#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int bankBalance = 0;

std::mutex balanceMutex;

void depositMoney()
{
    for (int i = 0; i < 100000; ++i)
    {
        bankBalance++;
    }
}

/**
 * You just fixed the bug happens when using depositMoney, but at what cost?

If you run both programs and time them, the Mutex version is significantly slower. Why? Because you just took 10 parallel threads and forced them to wait in a single-file line at a bottleneck. They aren't truly parallel anymore when they hit that lock.

This leads to the ultimate challenge in high-performance C++ system design: Lock-Free Programming using std::atomic.
 */
void depositMoneySafely()
{
    for (int i = 0; i < 100000; ++i)
    {
        // --- THE DANGEROUS WAY (Manual Lock/Unlock) ---
        // balanceMutex.lock();
        // bankBalance++;
        // balanceMutex.unlock();
        // Why is this dangerous? If bankBalance++ throws an error and crashes,
        // unlock() is never called. The entire program freezes forever (A Deadlock).

        // --- THE C++ SENIOR WAY (RAII) ---
        // std::lock_guard is a Smart Pointer for Mutexes!
        // It locks the mutex in its constructor.
        // When the loop iteration ends, the lock_guard is destroyed,
        // and its destructor automatically calls unlock()!

        std::lock_guard<std::mutex> lock(balanceMutex);
        bankBalance += 1; // Simulate a deposit of $1
    } // <- lock_guard is destroyed here, mutex is unlocked automatically
}

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; i++)
    {
        threads.push_back(std::thread(depositMoneySafely));
    }

    for (std::thread &thread : threads)
    {
        thread.join();
    }

    std::cout << "Expected balance: $1000000" << std::endl;

    std::cout << "Actual balance: $" << bankBalance << std::endl;

    return 0;
}