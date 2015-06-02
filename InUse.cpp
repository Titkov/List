#include <iostream>
#include "List.h"
#include "ListError.h"
using namespace std;

int main()
{
    List<int> l;

    try {
        l.back();
    } catch(ListError ex) {
        cout<<"ListError: "<<ex.get_message()<<endl;
    }

    try {
        l.front();
    } catch(ListError ex) {
        cout<<"ListError: "<<ex.get_message()<<endl;
    }

    l.push_back(10);
    cout << l.back() << endl;

    l.push_back(20);
    cout << l.back() << endl;

    l.push_front(-10);
    cout << l.front() << endl;

    l.push_front(-20);
    cout << l.front() << endl;

    List<int>::iterator it=l.begin();
    List<int>::iterator it1=l.end();

    if(it!=it1)
    {
        cout<<"Works"<<"\n";
    }

    List<int> l2(l);

    while(it.has_next() && it.get_data()!= 10)
    {
        it.next();
    }
    l.insert(it, 0);

    it=l.erase(it);

    cout << l.size(l) <<"\n";

    it=l.erase(it);

    cout << l.size(l)<<"\n";

    it != it1;

    cout << l.size(l) << "\n";

    List<int> l1(l);

    l.clear();

    List<char const*> l3;
    l3.push_front("John");
    l3.push_back("boy");
    cout<<l3.front()<<"\n";
    cout<<l3.back();

    l2=l1;

    cout<<endl;

    List<int> list1;

    list1.push_front(100);

    list1.push_front(200);

    list1.push_front(300);

    list1.push_back(777);

    cout << list1.back() << endl; //777

    list1.pop_back();

    cout << list1.back() << endl; //100

    cout << list1.front() << endl; //300

    list1.pop_front();

    cout << list1.front() << endl; //200

    List<int> list2;

    list2.push_back(616);

    list2.push_front(515);

    list2.push_front(313);

    list2.push_back(777);

    //Извежда 313 515 616 777

    List<int>::iterator itTerm2 = list2.terminator();
    for (List<int>::iterator it = list2.begin(); it != itTerm2; it.next())

    {

    cout << it.get_data() << " ";

    }

    cout << endl;

    List<char const*> list3;

    list3.push_back("vidi");

    list3.push_back("vici");

    List<char const*>::iterator iter = list3.begin();

    list3.insert(iter, "Veni");

    //Извежда Veni vidi vici

    List<char const*>::iterator itTerm3 = list3.terminator();
    for (List<char const*>::iterator it = list3.begin(); it != itTerm3; it.next())

    {

    cout << it.get_data() << " ";

    }

    cout << endl;

    List<char const*> list4;

    list4.push_back("Divide");

    list4.push_back("et");

    list4.push_back("impera");

    //Извежда Divide et impera
    List<char const*>::iterator itTerm4 = list4.terminator();
    for (List<char const*>::iterator it = list4.begin(); it != itTerm4; it.next())

    {

    cout << it.get_data() << " ";

    }

    List<char const*>::iterator mid = list4.begin();
    mid.next();

    list4.erase(mid);

    //Извежда Divide impera

    cout<<endl;

    for (List<char const*>::iterator it = list4.begin(); it != itTerm4; it.next())

    {

    cout << it.get_data() << " ";

    }

    cout << endl;

    return 0;
}
