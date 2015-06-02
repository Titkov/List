#ifndef LISTERROR_H_INCLUDED
#define LISTERROR_H_INCLUDED

#include <iostream>
using namespace std;

class ListError
{
    const char *const m_cMessage;

    public:
        ListError(const char *const message=0)
        : m_cMessage(message)
        {}

        const char *const get_message() const
        {
            return m_cMessage;
        }
};

#endif // LISTERROR_H_INCLUDED
