#include <assert.h>
#include <iostream>
#include "SinglyLinkedList.h"

void test_constructor() {
    SinglyLinkedList<int> lst = {100, 200, 300, 400, 500};
    assert(*lst.at(0) == 100);
    assert(*lst.at(1) == 200);
    assert(*lst.at(2) == 300);
    assert(*lst.at(3) == 400);
    assert(*lst.at(4) == 500);
    assert(lst.size() == 5);
}

void test_push_back() {
    SinglyLinkedList<int> lst = {100, 200, 300, 400, 500};
    lst.push_back (600) ;
    assert(*lst.at(0) == 100);
    assert(*lst.at(1) == 200);
    assert(*lst.at(2) == 300);
    assert(*lst.at(3) == 400);
    assert(*lst.at(4) == 500);
    assert(*lst.at(5) == 600);
    assert(lst.size() == 6);
    SinglyLinkedList<int> lst1 = {10, 20, 30, 40, 50};
    lst1.push_back (6) ;
    assert(*lst1.at(0) == 10);
    assert(*lst1.at(1) == 20);
    assert(*lst1.at(2) == 30);
    assert(*lst1.at(3) == 40);
    assert(*lst1.at(4) == 50);
    assert(*lst1.at(5) == 6);
    assert(lst1.size() == 6);

}
void test_push_front() {
    SinglyLinkedList<int> lst = {100, 200, 300, 400, 500};
    lst.push_front (700) ;

    assert(*lst.at(0) == 700);
    assert(*lst.at(1) == 100);
    assert(*lst.at(2) == 200);
    assert(*lst.at(3) == 300);
    assert(*lst.at(4) == 400);
    assert(*lst.at(5) == 500);
    assert(lst.size() == 6);

}

void test_remove() {
    //Case 1- Removing the only node from uni-node list
    SinglyLinkedList<int> lst = {100};
    assert(*lst.at(0) == 100);
    assert (lst.size()== 1) ;
    lst.remove(0);
    //After removing the only node of uni-node list, size will be 0
    assert (lst.size()== 0) ;
    //Case 2- Removing the first node pointed by head in multi_node list
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    assert(lst1.sum(lst1) == 1500);
    lst1.remove(0);
    assert(*lst1.at(0) == 200);
    assert(*lst1.at(1) == 300);
    assert(*lst1.at(2) == 400);
    assert(*lst1.at(3) == 500);
    //Case 3- Removing the last node pointed by tail in multi_node list
    SinglyLinkedList<int> lst2 = {100, 200, 300, 400, 500};
    assert(lst2.sum(lst2) == 1500);
    lst2.remove (4) ;
    assert(*lst2.at(0) == 100);
    assert(*lst2.at(1) == 200);
    assert(*lst2.at(2) == 300);
    assert(*lst2.at(3) == 400);
    //Case 4- Removing the non_head node in multi_node list
    SinglyLinkedList<int> lst3 = {100, 200, 300, 400, 500};
    lst3.remove (2) ;
    assert(*lst3.at(0) == 100);
    assert(*lst3.at(1) == 200);
    assert(*lst3.at(2) == 400);
    assert(*lst3.at(3) == 500);
    assert(lst3.size() == 4);

    SinglyLinkedList<int> lst4 = {100, 200, 300, 400, 500};
    lst4.remove(1);
    assert(*lst4.at(0) == 100);
    assert(*lst4.at(1) == 300);
    assert(*lst4.at(2) == 400);
    assert(*lst4.at(3) == 500);
    assert(lst4.size() == 4);
    SinglyLinkedList<int> lst5 = {100, 200};
    lst5.remove(1);
    assert(*lst5.at (0) == 100) ;
    assert(lst5.size() == 1 );


}
void test_insert()
{
    SinglyLinkedList<int> lst4 = {100, 200, 300, 400, 500,600,700,800,900};
    //Before insertion @ 8 is 900
    assert(*lst4.at(8) == 900);
    assert(lst4.size()==9) ;
    //Inserting 45 @ 8
    lst4.insert (8, 45) ;
    //After insertion 45 @ 8
    assert(*lst4.at(8) == 45);
    assert(*lst4.at(9) == 900);
    assert(lst4.size()==10) ;
    //Inserting 55 @ 9
    lst4.insert (9,55) ;
    //After insertion
    assert(*lst4.at(9) == 55);
    assert(*lst4.at(10) == 900);
    assert(lst4.size()==11) ;
    //Before inserting 65 @ 2
    assert(*lst4.at(2) == 300);
    //Inserting 65 @ 2
    lst4.insert(2,65) ;
    //After inserting 65 @ 2
    assert(*lst4.at(2) == 65);
    assert(*lst4.at(3) == 300);
    assert(lst4.size()==12) ;

}

void test_append() {
    SinglyLinkedList<int> lst = {};
    assert (lst.size () == 0) ;
    SinglyLinkedList<int> lst1 = {10,20,30,40,50};
    //Appending an empty list with non-empty list
    lst.append(lst1);
    assert(*lst.at(0) == 10);
    assert(*lst.at(1) == 20);
    assert(*lst.at(2) == 30);
    assert(*lst.at(3) == 40);
    assert(*lst.at(4) == 50);
    assert (lst.size () == 5) ;
    SinglyLinkedList<int> lst2 = {60,70,80,90,100};
    //Appending a non-empty list with non-empty list
    lst.append(lst2);
    assert(*lst.at(0) == 10);
    assert(*lst.at(1) == 20);
    assert(*lst.at(2) == 30);
    assert(*lst.at(3) == 40);
    assert(*lst.at(4) == 50);
    assert(*lst.at(5) == 60);
    assert(*lst.at(6) == 70);
    assert(*lst.at(7) == 80);
    assert(*lst.at(8) == 90);
    assert(*lst.at(9) == 100);
    assert (lst.size () == 10) ;
    SinglyLinkedList<int> lst3 = {};
    //Appending a non-empty list with an empty list
    lst.append(lst3);
    assert (lst.size () == 10) ;
}


void test_sum() {
    //Sum of a multi-node list is addition of integers in all nodes
    SinglyLinkedList<int> lst = {100, 200, 300, 400, 500};
    assert(lst.sum(lst) == 1500);
    //Sum of an empty list is 0
    SinglyLinkedList<int> lst1 = {};
    assert(lst1.sum(lst1) == 0);
    //Sum of a uni-node list is equal to the integer in the node
    SinglyLinkedList<int> lst2 = {300};
    assert(lst2.sum(lst2) == 300);
}
void test_is_equal ()
{
    SinglyLinkedList<int> lst = {};
    SinglyLinkedList<int> lst1 = {20};
    //Lists are not equal
    assert(!(lst.is_equal(&lst,&lst1))) ;
    SinglyLinkedList<int> lst2 = {};
    //Both lists are empty so are equal
    assert(lst.is_equal(&lst,&lst2)) ;
    SinglyLinkedList<int> lst3 = {10,20,30,40,50};
    SinglyLinkedList<int> lst4 = {10,20,30,40,50,60,70,80};
    //Both lists are non_empty but different
    assert(!(lst3.is_equal(&lst3,&lst4))) ;
    SinglyLinkedList<int> lst5 = {60,70,80};
    //Appending lst3 with lst5 makes it equal to lst 4
    lst3.append(lst5);
    //Both lists are non_empty but equal
    assert(lst3.is_equal(&lst3,&lst4)) ;

}

int main() {
    test_constructor();
    test_remove();
    test_insert();
    test_push_back();
    test_push_front();
    test_append();
    test_sum();
    test_is_equal () ;
}

