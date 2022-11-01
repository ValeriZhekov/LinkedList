#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.hpp"
TEST_CASE("Operations on LinkedList")
{
    LinkedList<char> list;
    int j = 0;
    for (int i = 'a'; i <= 'f'; i++)
    {
        list.insertAtPos(i, j);
        j++;
    }
    list.insertAtPos('x',2);
    SECTION("Adding Nodes")
    {
    
    CHECK(list.getElementAtPos(0)=='a');
    CHECK(list.getElementAtPos(2)=='x');
    CHECK(list.getElementAtPos(3)=='c');
    CHECK(list.getElementAtPos(6)=='f');
    }
    list.removeAtPos(3);
    SECTION("Removing Nodes")
    {
    
    CHECK(list.getElementAtPos(0)=='a');
    CHECK(list.getElementAtPos(3)=='d');
    CHECK(list.getElementAtPos(5)=='f');
    }
    LinkedList<char> list2(list);
    SECTION("Copying LinkedList")
    {
    CHECK(list2.getElementAtPos(0)=='a');
    CHECK(list2.getElementAtPos(3)=='d');
    CHECK(list2.getElementAtPos(5)=='f');
    CHECK(list2.getSize()==list.getSize());
    }
    LinkedList<char> list3;
    list3=list;
    SECTION("Operator =")
    {
    CHECK(list3.getElementAtPos(0)=='a');
    CHECK(list3.getElementAtPos(3)=='d');
    CHECK(list3.getElementAtPos(5)=='f');
    CHECK(list3.getSize()==list.getSize());
    }
    SECTION("Operator ==")
    {
        CHECK(list==list3);
        list3.insertAtPos('X',2);
        CHECK(!(list==list3));
    }
}