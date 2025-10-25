#ifndef QUEUEFACTORY_HPP
#define QUEUEFACTORY_HPP

template <typename T>
class QueueFactory
{
    public:
    Queue<T>* GetQueue(int = 0);
};

#include "QueueFactory.tpp"
#endif //QUEUEFACTORY_HPP
