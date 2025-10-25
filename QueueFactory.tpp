#include "QueueFactory.hpp"
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

template <typename T>
Queue<T>* QueueFactory<T>::GetQueue(int length)
{
    if (length != 0) return new ArrayQueue<T>(length);
    return new LinkedQueue<T>();
}
