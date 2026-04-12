#include <iostream>
#include <thread>
#include <chrono> // for simulating time delays

void downloaFile(std::string fileName)
{
    std::cout << "Starting download of " << fileName << "..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate a time-consuming download
    std::cout << "Finished downloading " << fileName << "!" << std::endl;
}

int main()
{
    std::cout << "Initiating file download in a separate thread..." << std::endl;
    std::thread downloadThread(downloaFile, "exammple_file.txt");
    std::cout << "Main thread is free to do other work while the file is downloading..." << std::endl;
    downloadThread.join(); // Wait for the download thread to finish before exiting main
    std::cout << "All tasks completed. Exiting program." << std::endl;
    return 0;
}