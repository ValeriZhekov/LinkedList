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
}