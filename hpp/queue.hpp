#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "linked_list.hpp"

namespace myDS
{
    template <class T>
    class queue : linked_list<T>
    {
    public:
        queue() {}
        ~queue() {}
        
        bool empty()
        {
            return !linked_list<T>::__size;
        }

        int size()
        {
            return linked_list<T>::__size;
        }

        void push(T element)
        {
            linked_list<T>::push_back(element);
        }

        T pop()
        {
            return linked_list<T>::pop_front();
        }

        T top()
        {
            return linked_list<T>::top();
        }

    };

}



#endif