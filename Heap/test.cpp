#include "Heap.h"
#include <assert.h>
void testQueue (int arr[]);
void testDequeue (int arr[]);

int main()
{

    Heap_size = 5 ;
    int arr1 [Heap_size] = {5,4,1,8,5} ;
    //int arr1 [Heap_size] = {1,2,3,4,5,6,7,8,9,10,11,22,23,24,25,14,15,16,17,33,44,45,1,2,3} ;
    cout << "INITIAL Array" << endl ;
    for(int i=0;i<Heap_size;i++)
    {
        cout<<arr1[i]<<"\t";
    }
    cout << endl ;
    //Creating Heap with the given data
    for(int i=Heap_size/2;i>=0;i--)
    heapify(arr1,i);
    cout << "Heapified Array" << endl ;
    for(int i=0;i<Heap_size;i++)
    {
        cout<<arr1[i]<<"\t";
    }
    cout << endl ;
    //Testing queue()
    testQueue (arr1);
    //Testing dequeue()
    testDequeue(arr1);
    return 0;
}

void testQueue(int arr[])
{

    queue(arr,Heap_size, 6) ;
    assert(arr[0] == 8) ;
    assert(arr[1] == 5) ;
    assert(arr[2] == 6) ;
    assert(arr[3] == 4) ;
    assert(arr[4] == 5) ;
    assert(arr[5] == 1) ;
    queue(arr,Heap_size, 11) ;
    assert(arr[0] == 11) ;
    assert(arr[1] == 5) ;
    assert(arr[2] == 8) ;
    assert(arr[3] == 4) ;
    assert(arr[4] == 5) ;
    assert(arr[5] == 1) ;
    assert(arr[6] == 6) ;

    queue(arr,Heap_size, 7) ;
    assert(arr[0] == 11) ;
    assert(arr[1] == 7) ;
    assert(arr[2] == 8) ;
    assert(arr[3] == 5) ;
    assert(arr[4] == 5) ;
    assert(arr[5] == 1) ;
    assert(arr[6] == 6) ;
    assert(arr[7] == 4);

}
void testDequeue(int arr [])
{
    int MaxHeap = dequeue(arr,Heap_size);
    assert(MaxHeap==11) ;

    //Testing heap after removing MaxHeap
    assert(arr[0] == 8) ;
    assert(arr[1] == 7) ;
    assert(arr[2] == 6) ;
    assert(arr[3] == 5) ;
    assert(arr[4] == 5) ;
    assert(arr[5] == 1) ;
    assert(arr[6] == 4) ;


    MaxHeap = dequeue(arr,Heap_size);
    assert(MaxHeap==8) ;
    //Testing heap after removing MaxHeap
    assert(arr[0] == 7) ;
    assert(arr[1] == 5) ;
    assert(arr[2] == 6) ;
    assert(arr[3] == 4) ;
    assert(arr[4] == 5) ;
    assert(arr[5] == 1) ;


    MaxHeap = dequeue(arr,Heap_size);
    assert(MaxHeap==7) ;
    //Testing heap after removing MaxHeap
    assert(arr[0] == 6) ;
    assert(arr[1] == 5) ;
    assert(arr[2] == 1) ;
    assert(arr[3] == 4) ;
    assert(arr[4] == 5) ;
}
