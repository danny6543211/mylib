#ifndef STACK_HPP
#define STACK_HPP
#include "linked_list.hpp"

namespace myDS
{
    template <class T>
    class stack : private linked_list<T>
    {
    public:
        stack() {}
        ~stack() {}

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
            linked_list<T>::push_front(element);
        }

        T pop()
        {
            return linked_list<T>::pop_front();
        }

        T top()
        {
            return linked_list<T>::top();
        }


    
    private:


    };
}


#endif