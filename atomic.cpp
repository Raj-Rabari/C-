#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

// 1. Declare the variable as atomic
// We do NOT need a std::mutex anymore!
std::atomic<int> bankBalance(0); // Atomic variable to ensure thread safety

void depositMoneySafely()
{
    for (int i = 0; i < 100000; ++i)
    {
        // 2. The CPU magic
        // This looks like standard C++, but the compiler translates this
        // into a special hardware instruction (like LOCK XADD on x86 CPUs).
        // It happens in one unbreakable hardware step. No sleeping!
        bankBalance++; // Atomically increment the bank balance
    }
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

    std::cout << "Expected bank balance: $1000000" << std::endl;
    std::cout << "Actual bank balance: $" << bankBalance.load() << std::endl; // Use load() to read the atomic variable

    return 0;
}