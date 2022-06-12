#include <string>
#include "dataType.h"

#include "Counting_Sort.h"
#include "DataGenerator.h"
#include "Quick_Sort.h"
#include "Radix_Sort.h"
#include "Shaker_Sort.h"
#include "Shell_Sort.h"
#include "Flash_Sort.h"
#include "Selection_Sort.h"
#include "Insertion_Sort.h"
#include "Bubble_Sort.h"
#include "heap_sort.h"
#include "Merge_Sort.h"

using namespace std;
std::string Algorithm_Option(string key, bool just_name, unsigned long long &comparison, int a[] = nullptr, int n = 0)
{
    string al_name;
    comparison = 0;
    switch (algorithm[key])
    {
    // Selection, Insertion, Bubble, Shaker, Shell,
    case Selection:
    {
        al_name = "Selection sort";
        if (just_name)
            return al_name;
        selectionSort(a,n,comparison);
    }
    break;
    case Insertion:
    {
        al_name = "Insertion sort";
        if (just_name)
            return al_name;
        insertionSort(a,n,comparison);
    }
    break;
    case Bubble:
    {
        al_name = "Bubble sort";
        if (just_name)
            return al_name;
        bubbleSort(a,n,comparison);
    }
    break;
    case Shaker:
    {
        al_name = "Shaker sort";
        if (just_name)
            return al_name;
        shakerSort(a, n, comparison);
    }
    break;
    case Shell:
    {
        al_name = "Shell sort";
        if (just_name)
            return al_name;
        shellSort(a, n, comparison);
    }
    break;
        // Heap, Merge, Quick,
    case Heap:
    {
        al_name = "Heap sort";
        if (just_name)
            return al_name;
        heapSort(a,n,comparison);
    }
    break;
    case Merge:
    {
        al_name = "Merge sort";
        if (just_name)
            return al_name;
        mergeSort(a,0,n-1,comparison);
    }
    break;
    case Quick:
    {
        al_name = "Quick sort";
        if (just_name)
            return al_name;
        quickSort(a, 0, n - 1, comparison); // 0: first element in the array, n-1: last element in the array
    }
    break;
        // Counting, Radix, Flash
    case Counting:
    {
        al_name = "Counting sort";
        if (just_name)
            return al_name;
        countingSort(a, n, comparison);
    }
    break;
    case Radix:
    {
        al_name = "Radix sort";
        if (just_name)
            return al_name;
        radixSort(a, n, comparison);
    }
    break;
    case Flash:
    {
        al_name = "Flash sort";
        if (just_name)
            return al_name;
        flashSort(a, n, comparison);
    }
    break;
    default:
        break;
    }
    return al_name;
}


std::string Algorithm_Option(string key, bool just_name, clock_t &timer, int a[] = nullptr, int n = 0)
{
    string al_name;
    clock_t start, end;
    switch (algorithm[key])
    {
    // Selection, Insertion, Bubble, Shaker, Shell,
    case Selection:
    {
        al_name = "Selection sort";
        if (just_name)
            return al_name;
        start = clock();
        selectionSort(a,n);
        end = clock();
    }
    break;
    case Insertion:
    {
        al_name = "Insertion sort";
        if (just_name)
            return al_name;
        start = clock();
        insertionSort(a,n);
        end = clock();
    }
    break;
    case Bubble:
    {
        al_name = "Bubble sort";
        if (just_name)
            return al_name;
        start = clock();
        bubbleSort(a,n);
        end = clock();
    }
    break;
    case Shaker:
    {
        al_name = "Shaker sort";
        if (just_name)
            return al_name;
        start = clock();
        shakerSort(a, n);
        end = clock();
    }
    break;
    case Shell:
    {
        al_name = "Shell sort";
        if (just_name)
            return al_name;
        start = clock();
        shellSort(a, n);
        end = clock();
    }
    break;
        // Heap, Merge, Quick,
    case Heap:
    {
        al_name = "Heap sort";
        if (just_name)
            return al_name;
        start = clock();
        heapSort(a,n);
        end = clock();
    }
    break;
    case Merge:
    {
        al_name = "Merge sort";
        if (just_name)
            return al_name;
        start = clock();
        mergeSort(a,0,n-1);
        end = clock();
    }
    break;
    case Quick:
    {
        al_name = "Quick sort";
        if (just_name)
            return al_name;
        start = clock();
        quickSort(a, 0, n - 1); // 0: first element in the array, n-1: last element in the array
        end = clock();
    }
    break;
        // Counting, Radix, Flash
    case Counting:
    {
        al_name = "Counting sort";
        if (just_name)
            return al_name;
        start = clock();
        countingSort(a, n);
        end = clock();
    }
    break;
    case Radix:
    {
        al_name = "Radix sort";
        if (just_name)
            return al_name;
        start = clock();
        radixSort(a, n);
        end = clock();
    }
    break;
    case Flash:
    {
        al_name = "Flash sort";
        if (just_name)
            return al_name;
        start = clock();
        flashSort(a, n);
        end = clock();
    }
    break;
    default:
        break;
    }
    timer = (end - start);
    return al_name;
}