#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include "ListError.h"
using namespace std;

template <typename T>

class List
{
    struct Node
    {
            T m_data;
            Node* m_next;
            Node* m_prev;

            Node(T val) :
                m_next(0), m_prev(0), m_data(val)
            {}
    };

    public:

        Node* m_head;

        List() : m_head(new Node(0))
        {
            m_head->m_next = m_head->m_prev = m_head;
        }

        List(List &L1) : List()
        {
           for(iterator it=L1.begin(); it.has_next();)
            {
                push_back(it.get_data());
                it.next();
            }
        }

        ~List()
        {
            while(!empty())
            {
                pop_front();
            }

            delete m_head;
        }

        List& operator= (List &L1)
        {
            clear();

            for(iterator it=L1.begin(); it.has_next();)
            {
                push_back(it.get_data());
                it.next();
            }

            return *this;
        }

        bool empty() const
        {
            return m_head == m_head->m_next;
        }

        void push_front(T val)
        {
            Node* front=m_head->m_next;

            Node* ptr=new Node(val);

            m_head->m_next=ptr;
            ptr->m_prev=m_head;

            front->m_prev=ptr;
            ptr->m_next=front;
        }

        void pop_front()
        {
            if(empty())
            {
                throw ListError("pop_front(): list empty...");
            }

            Node* front=m_head->m_next;
            Node* new_front=front->m_next;

            m_head->m_next=new_front;
            new_front->m_prev=m_head;

            delete front;
        }

        void push_back(T val)
        {
            Node* back=m_head->m_prev;

            Node* ptr=new Node(val);

            back->m_next=ptr;
            ptr->m_prev=back;

            m_head->m_prev=ptr;
            ptr->m_next=m_head;
        }

        void pop_back()
        {
            if(empty())
            {
                throw ListError("pop_back(): list empty...");
            }

            Node* back=m_head->m_prev;
            Node* new_back=back->m_prev;

            new_back->m_next=m_head;
            m_head->m_prev=new_back;

            delete back;
        }

        T front() const
        {
            if(empty())
            {
                throw ListError("front(): list is empty");
            }

            return m_head->m_next->m_data;
        }

        T back() const
        {
            if(empty())
            {
                throw ListError("back(): list is empty");
            }

            return m_head->m_prev->m_data;
        }

        class iterator
        {
            friend class List;

            const List *const m_list;

            iterator(const List* l, Node* current)
                : m_list(const_cast<List*>(l)), m_current(current)
            {}

        public:

            Node* m_current;

            iterator& operator= (const iterator &it)
            {
                m_current = it.m_current;

                return *this;
            }

            bool has_next() const
            {
                return m_current != m_list->m_head;
            }

            void next()
            {
                m_current = m_current->m_next;
            }

            T get_data() const
            {
                if(m_current!=m_list->m_head)
                {
                    return m_current->m_data;
                }

                throw ListError("iterator::get_data()...");
            }

            bool operator!= (iterator &I1)
            {
                return this->m_current != I1.m_current;
            }
        };

        iterator begin()
        {
            return iterator(this, m_head->m_next);
        }

        iterator end()
        {
            return iterator(this, m_head->m_prev);
        }

        iterator terminator()
        {
            return iterator(this, m_head);
        }

        iterator insert(iterator it, T val)
        {
            Node* n=new Node(val);
            Node* prev=it.m_current->m_prev;

            n->m_next=it.m_current;
            it.m_current->m_prev=n;

            prev->m_next=n;
            n->m_prev=prev;

            return iterator(this, n);
        }

        iterator erase(iterator it)
        {
            if(empty())
            {
                throw ListError("erase(): empty list...");
            }
            if(it.m_current==it.m_list->m_head)
            {
                throw ListError("erase(): positioned on head...");
            }

            Node* ptr=it.m_current;
            Node* prev=it.m_current->m_prev;
            Node* next=it.m_current->m_next;

            prev->m_next=next;
            next->m_prev=prev;

            delete it.m_current;

            return iterator(it.m_list, next);
        }

        int size(List &L1)
        {
            int counter=0;

            for(iterator it=L1.begin(); it.has_next();)
            {
                counter++;
                it.next();
            }

            return counter;
        }

        void clear()
        {
            while(!empty())
            {
                pop_front();
            }
        }
};

#endif // LIST_H_INCLUDED
