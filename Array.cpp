#include "Array.h"
#include<iostream>
#include <ctime> 

DynamicArray::DynamicArray() : ptr(nullptr), size(0)
{}

DynamicArray::DynamicArray(int S)
{
    size = S;
    ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray &a)
{
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}

DynamicArray::~DynamicArray()
{
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
}

void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}

void DynamicArray::Output() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << ptr[i] << "\t";
    }
}

int* DynamicArray::GetPointer() const
{
    return ptr;
}

int DynamicArray::GetSize() const
{
    return size;
}

void DynamicArray::ReSize(int s)
{
    if (size != s) {
        int* newPointer = new int[s];

        for (int i = 0; i < size; i++) {
            newPointer[i] = ptr[i];
        }
        for (int i = size; i < s; i++) {
            newPointer[i] = 0;
        }

        delete[] ptr;
        ptr = newPointer;
        size = s;
    }
    else {
        std::cout << "Array has the same size." << std::endl;
    }
}

void DynamicArray::Sort()
{
    for (int i = 1; i < size; i++) {
        int key = ptr[i];
        int j = i - 1;

        while (j >= 0 && ptr[j] > key) {
            ptr[j + 1] = ptr[j];
            j = j - 1;
        }
        ptr[j + 1] = key;
    }
}

int DynamicArray::Search(int a)
{
    for (int i = 0; i < size; i++) {
        if (ptr[i] == a) {
            return i;
        }
    }
    return -1;
}

void DynamicArray::Reverse()
{
    int startIndex = 0;
    int endIndex = size - 1;

    while (startIndex < endIndex) {
        int temp = ptr[startIndex];
        ptr[startIndex] = ptr[endIndex];
        ptr[endIndex] = temp;
        startIndex++;
        endIndex--;
    }
}