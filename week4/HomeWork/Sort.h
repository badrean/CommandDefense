#pragma once
class Sort
{
    // add data members
    unsigned elements_nr;
    int* list;
    bool ordered = 0;

public:

    // add constuctors
    Sort(unsigned count, int min, int max);

    Sort() : elements_nr(6), list(new int[6] { 3,1,5,2,4,6 }) {}

    Sort(unsigned count, int* list);

    Sort(unsigned count, ...);

    Sort(const char* string);


    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

    int partition(int* arr, int low, int high);
};

