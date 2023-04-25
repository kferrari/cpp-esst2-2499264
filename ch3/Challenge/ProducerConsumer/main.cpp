#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    auto promise = std::promise<int>();

    auto producer = std::thread([&]
    {
    
        for(int i=0; i<=10 ; i++)
        {            
            std::this_thread::sleep_for(chrono::milliseconds(1000));
            promise.set_value(i*i);
            promise = std::promise<int>();
        }
    });


    auto consumer = std::thread([&]
    {
        int r = 0;
        while(r < 100)
        {
            // TODO: Consumer Code implementieren, bei dem promises und futures für die
            // Interthread-Kommunikation verwendet werden.


            std::cout << "Incoming Result: ";
            auto future = promise.get_future();
            r = future.get();
            
            std::cout << r;
            std::cout << std::endl;
        }

    });

    producer.join();
    consumer.join();
    return 0;
}
