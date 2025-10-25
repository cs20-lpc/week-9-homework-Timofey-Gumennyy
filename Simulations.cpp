#include "ArrayQueue.hpp"
#include "QueueFactory.hpp"
#include <iostream>
#include <random>
#include <chrono>

int main()
{
    // Scenario 1
    cout << "----------------------------Scenario 1----------------------------\n\n";
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    QueueFactory<int>* queueFactory = new QueueFactory<int>();
    int maxSize = 10;
    Queue<int>* ticketCounter = queueFactory->GetQueue(maxSize);

    for (int i = 0; i < 100; ++i)
    {
        int randomNumberInRange = std::rand() % 3 - 1;
        if (randomNumberInRange >= 0 && ticketCounter->getLength() != maxSize)
        {
            ticketCounter->enqueue(i);
            std::cout << "Serving a customer with index: " << i << std::endl;
        }
        else if (!ticketCounter->isEmpty())
        {
            std::cout << "Removed customer with index: " << ticketCounter->front() << std::endl;
            ticketCounter->dequeue();
        }

        if (!ticketCounter->isEmpty())
        {
            cout << "Customers on line: ";
            ticketCounter->PrintAll();
            cout << endl;
        }

    }

    // Scenario 2
    cout << "\n\n----------------------------Scenario 2----------------------------\n\n";
    Queue<int>* bank = queueFactory->GetQueue();

    for (int i = 0; i < 100; ++i)
    {
        int randomNumberInRange = std::rand() % 3 - 1;
        if (randomNumberInRange >= 0)
        {
            bank->enqueue(i);
            std::cout << "Customer arrived: " << i << std::endl;
        }
        else if (!bank->isEmpty())
        {
            std::cout << "Removed customer with index: " << bank->front() << std::endl;
            bank->dequeue();
        }

        if (!bank->isEmpty())
        {
            cout << "Customers on line: ";
            bank->PrintAll();
            cout << endl;
        }

    }
    return 0;
}

