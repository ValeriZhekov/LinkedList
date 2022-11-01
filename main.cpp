#include <iostream>
#include "LinkedList.hpp"
int main()
{LinkedList<char> l; int j=0;
for (char i='a'; i<'g'; i++)
{l.insertAtPos(i,j); j++; }
l.insertAtPos('x',5);
l.print();

    return 0;
}