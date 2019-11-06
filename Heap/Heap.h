#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include <cstdlib>
using namespace std;

void heapify(int *data, size_t size) ;
void queue(int* data, size_t& size, int i);
int dequeue(int* data, size_t& size);
void siftUp(int nodeIndex, int* data) ;
void siftDown(int nodeIndex, int * data);
size_t Heap_size;


void heapify(int *data, size_t size)
{

    int l,r,smallest,temp;
    l=2*size+1;
    r=2*size+2;
    if(l<Heap_size && data[l]>data[size])
    {
        smallest=l;
    }
    else
    {
       smallest=size;
    }
    if(r<Heap_size && data[r]>data[smallest])
    {
        smallest=r;
    }
    if(smallest!=size)
    {
        temp=data[size];
        data[size]=data[smallest];
        data[smallest]=temp;
        heapify(data,smallest);
    }
}
void queue(int* data, size_t& size, int i)
{
    size++;
    data[size - 1] = i;
    siftUp(size - 1,data);

}

void siftUp(int nodeIndex, int * data)
{
    int parentIndex, tmp;
    if (nodeIndex != 0)
    {
        parentIndex = (nodeIndex - 1) / 2;
        if (data[parentIndex] < data[nodeIndex])
        {
            tmp = data[parentIndex];
            data[parentIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            siftUp(parentIndex, data);
        }
    }
}


void siftDown(int nodeIndex, int * data)
{
    int leftChildIndex, rightChildIndex, MaxIndex, tmp;
    leftChildIndex = 2 * nodeIndex + 1;
    rightChildIndex = 2 * nodeIndex + 2;
    if (rightChildIndex >= Heap_size)
    {
        if (leftChildIndex >= Heap_size)
            return;
        else
            MaxIndex = leftChildIndex;
    }
    else
    {
        if (data[leftChildIndex] >= data[rightChildIndex])
                MaxIndex = leftChildIndex;
        else
                MaxIndex = rightChildIndex;
    }
    if (data[nodeIndex] < data[MaxIndex])
    {
        tmp = data[MaxIndex];
        data[MaxIndex] = data[nodeIndex];
        data[nodeIndex] = tmp;
        siftDown(MaxIndex, data);
    }
}

int dequeue(int* data, size_t& size)
{
    int temp = data [0];
    if (size==0)
    {
        cout << "Heap is empty" << endl ;
        exit(1);
    }

    else
    {

        data[0] = data[size- 1];
        size--;
        if (size > 0)
        siftDown(0, data);
    }
    return temp ;
}

#endif // HEAP_H
