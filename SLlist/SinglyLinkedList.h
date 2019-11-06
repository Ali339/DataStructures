#include <stddef.h>
#include <initializer_list>
using namespace std ;
#include <iostream>

template <class T>
class SinglyLinkedList
{
    // Nested class representing the nodes in the list.
    class SinglyLinkedListNode
    {
        public:
        //Member variables of class SinglyLinkedListNode
        //The value stored in this node.
        T value;
        //The next node in the sequence.
        SinglyLinkedListNode *next;

        //Constructor with one argument
        SinglyLinkedListNode(T value):
            value(value), next(nullptr) {}

        //Constructor with two arguments
        SinglyLinkedListNode(T value, SinglyLinkedListNode *next) :
            value(value), next(next) {}

        //Return the size (length) of the linked list.
        std::size_t size();
    };
    //Member variables of class SinglylinkedList
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

public:
    // Constructs a new SinglyLinkedList from an initializer_list of type T[].
    // This is mostly for convenience, especially when testing.
    SinglyLinkedList(std::initializer_list<T> items):head(nullptr),tail(nullptr)
    {
        if (items.size() == 0) {
            return;
        }
        // initializer_lists were designed to be used iteratively,
        // so thats what we do.
        // Can you think of how to write this recursively?
        auto it = items.begin();
        while (it != items.end()) {
            this->push_back(*it++);
        }
    }

    // Return a pointer to the value at the given index.
    // If the index is larger than the size of the list,
    // return a nullptr.
    // ASIDE: We will cover exceptions later.
    T* at(std::size_t i);

    // Pushes a new node onto the back of the list.
    void push_back(T value);

    // Pushes a new node onto the front of the list.
    void push_front(T value);

    // Return the size (length) of the linked list.
    std::size_t size();

    //Remove the specified node from the list.
    void remove(std::size_t i);

     //Insert the value at the index.
    void insert(std::size_t i, T value);

    // Append the given list to this one.
    void append(SinglyLinkedList<T> list);
    long sum(const SinglyLinkedList<int>& list);
    bool is_equal(SinglyLinkedList <T> * lhs, SinglyLinkedList <T> * rhs);
};

template <class T>
T* SinglyLinkedList<T>::at(std::size_t i) {
    //It checks the list is not empty or i is in the range (0 to size()-1)
    if (size () == 0 || i > size ())
        return nullptr ;
    SinglyLinkedListNode * current = head ;
    while (i)
    {
        current = current->next ;
        i-- ;
    }
    return &current->value ;
    }


template <class T>
void SinglyLinkedList<T>::push_back(T value) {
    //List is empty
    if (head == nullptr)
    {
        head = new SinglyLinkedListNode (value);
        //Tail and head pointing towards only one node created
        tail = head ;
    }
    //List is not empty
    else
    {
        //Adding node next to the tail
        //Invoking single argument constructor which sets next pointer to 0
        tail -> next = new SinglyLinkedListNode (value);
        //Updating Tail
        tail = tail->next ;
    }
}

template <class T>
void SinglyLinkedList<T>::push_front(T value) {
    //List is empty
    if (head == nullptr)
    {
        //Creating a new node
        head =  new SinglyLinkedListNode (value) ;
        //Tail and head pointing towards only one node created
        tail = head ;
    }
    else
        //List is not empty
        //Invoking 2 arguments constructor which sets next pointer to the current head
        head =  new SinglyLinkedListNode (value,head) ;
}

template <class T>
void SinglyLinkedList<T>::remove(std::size_t i) {

    //Validating that list is non-empty and node to remove is on valid position
    if( i < size() && head != nullptr)
    {
        //When there is only one node in the list
        if (head == tail)
        {
            delete head ;
            //head and tail are updated to nullptr
            head = tail = nullptr ;
        }
        //When removing the first node towards which head is currently pointing
        else if (*this->at(i) == head->value)
        {
            SinglyLinkedListNode * temp = head;
            //Updating the head to the next node
            head = head->next ;
            delete temp ;
        }
        //Removing non-head node at list has more than one node
        else
        {
            SinglyLinkedListNode * pred , *temp ;
            for (pred = head , temp = head->next ; temp != nullptr && *this->at(i)!= temp->value ;
            pred = pred->next , temp = temp ->next );

            {
                //The node being deleted is pointed by nor head neither tail
                //No need to update head or tail
                if (temp != 0)
                //No need for updating head or tail
                pred->next = temp ->next ;
                //The node being removed is the last one in the list having more than one node
                if (temp == 0)
                //tail needs to be updated to precedent node
                tail = pred ;
                delete temp ;
            }
        }
}
}
template <class T>
void SinglyLinkedList<T>::insert(std::size_t i, T value) {
    //Validating that inserting is different from push_front
    //Position of insertion is in range that is position 2nd(1) to last(size()-1)
    if (i > 0 && i < size())
    {
        SinglyLinkedListNode  * temp, *pred ;
        for (pred = head , temp = head->next ; temp != nullptr && *this->at(i)!= temp->value ;
        pred = pred->next , temp = temp ->next );
        pred->next= new  SinglyLinkedListNode (value, temp) ;
    }
}

template <class T>
void SinglyLinkedList<T>::append(SinglyLinkedList<T> list) {
    //Appending an empty list
    if (head == nullptr)
    {
        head = list.head ;
        tail = list.tail ;
    }
    //Appending non-empty list
    else
    {
        tail->next = list.head ;
        tail = list.tail ;
    }

}

template <class T>
std::size_t SinglyLinkedList<T>::size() {
    // I did this one for you.  I am such a nice guy!
    if (this->head == nullptr) {
        return 0;
    } else {
        return this->head->size();
    }
}

template <class T>
std::size_t SinglyLinkedList<T>::SinglyLinkedListNode::size() {
    // Seriously, I am the best.

    if (this == nullptr) {
        return 0;
    } else if (this->next == nullptr) {
        return 1;
    } else {
        return 1 + this->next->size();
    }
}

// Takes a reference to a list of integers as an argument,
// and returns the sum of the items in the list.
template <class T>
long SinglyLinkedList <T>:: sum(const SinglyLinkedList<int>& list) {
    long S = 0 ;
    for (int i = 0 ; this->at(i)!= nullptr  ; i++)
    {
        S += *this->at(i) ;
    }
    return S ;
}
template <class T>
bool SinglyLinkedList<T>::is_equal( SinglyLinkedList <T> * lhs,  SinglyLinkedList <T> * rhs)
{
    SinglyLinkedListNode * right = rhs->head ;
    SinglyLinkedListNode * left = lhs->head ;
    if (lhs->size() != rhs->size())
        return false ;
    else if (right == nullptr)
        return true ;

    else
    {
        while (right != nullptr)
        {
            if (right->value == left->value)
            {
                right = right->next ;
                left = left->next ;
            }
            else
                return false;
        }

    }
    return true ;
 }
