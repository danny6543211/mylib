#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>

template<class T>
struct list_node {
    T element;
    list_node *next;
};

namespace myDS
{
    template <class T>
    class linked_list
    {   
    public:
        linked_list() 
        {
            __size = 0;
            __head = nullptr;
        }

        ~linked_list() 
        {
            list_node<T> *p = __head;
            if (p == nullptr)
                return;
            else 
            {
                while (p != nullptr)
                {
                    list_node<T> *temp = p;
                    p = p->next;
                    free(temp);
                }
            }
        }

        int size() 
        {
            return __size;
        }

        bool empty() 
        {
            return !__size;    
        }

        T top() {
            if (__head == nullptr)
                throw "The list is empty, so there is no value at the top.";
            return __head->element;
        }

        void push_back(T element) 
        {
            list_node<T> *new_node = new list_node<T>;
            new_node->element = element;
            new_node->next = nullptr;

            list_node<T> *p = __head;
            if (p == nullptr)
                __head = new_node;
            else 
            {
                while (p->next != nullptr)
                    p = p->next;
                p->next = new_node;
            }
            __size++;
        }

        void push_front(T element)
        {
            list_node<T> *new_node = new list_node<T>;
            new_node->element = element;
            new_node->next = __head;
            __head = new_node;
            __size++;
        }

        T pop_back() 
        {   
            if (__head == nullptr)
                throw "Function pop_back when the list is empty is an illegal operation.";
            else if (__head->next == nullptr) 
            {
                T res = __head->element;
                free(__head);
                __head = nullptr;
                return res;
            }
            else 
            {
                list_node<T> *p = __head;
                while (p->next->next != nullptr)
                    p = p->next;
                T res = p->next->element;
                free(p->next);
                p->next = nullptr;
                return res;
            }
            __size--;
        }

        T pop_front()
        {
            if (__head == nullptr)
                throw "Function pop_front when the list is empty is an illegal operation.";
            T res = __head->element;
            list_node<T> *temp = __head;
            __head = __head->next;
            free(temp);
            __size--;

            return res;
        }

        // 默认升序 冒泡排序
        void sort()
        {
            if (__head == nullptr || __head->next == nullptr)
                return;
            for (int i = 0; i < __size-1; i++)
            {
                list_node<T> *p = __head;
                for (int j = 0; j < __size-i-1; j++)
                {
                    if (p->element > p->next->element)
                    {
                        T temp = p->element;
                        p->element = p->next->element;
                        p->next->element = temp;
                    }
                    p = p->next;
                }
            }    
        }

        void reverse()
        {
            linked_list<T> temp;
            int size = __size;
            for (int i = 0; i < size; i++)
            {
                temp.push_back(this->pop_front());
            }
            for (int i = 0; i < size; i++)
            {
                this->push_back(temp.pop_back());
            }
        }

        list_node<T> *find(T find_value)
        {
            if (__head == nullptr)
                return nullptr;
            
            list_node<T> *p = __head;
            while (p != nullptr)
            {
                if (p->element == find_value)
                {
                    return p;
                }
                p = p->next;
            }

            return nullptr;
        }

    protected:
        int __size;
        list_node<T>* __head;

    };

}

#endif