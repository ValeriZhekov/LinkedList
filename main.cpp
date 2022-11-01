#include <iostream>
#include "LinkedList.hpp"
int main()
{LinkedList<char> l,c; int j=0;
for (char i='a'; i<'g'; i++)
{l.insertAtPos(i,j); j++; }
l.insertAtPos('x',5);
c.insertAtPos('C',0);
c=l;
c.print(); 
std::cout<<(c==l);
c.insertAtPos('C',0);
std::cout<<(c==l);
    return 0;
}