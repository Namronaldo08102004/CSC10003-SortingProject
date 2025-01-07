#pragma once
#include "Library.h"

//* Huy's part
void HeapSortComp(vector<int> &arr, long long &comparisons);
void MergeSortComp(vector<int> &arr, long long &comparisons);
void RadixSortComp(vector<int> &arr, long long &comparisons);

void HeapSortTime(vector<int> &arr, double &time);
void MergeSortTime(vector<int> &arr, double &time);
void RadixSortTime(vector<int> &arr, double &time);

//* Minh's part
void QuickSortComp(vector<int> &arr, long long &comparisons);
void ShellSortComp(vector<int> &arr, long long &comparisons);
void CountingSortComp(vector<int> &arr, long long &comparisons);

void QuickSortTime(vector<int> &arr, double &time);
void ShellSortTime(vector<int> &arr, double &time);
void CountingSortTime(vector<int> &arr, double &time);

//* Nam's part
void ShakerSortComp(vector<int> &arr, long long &comparisons);
void FlashSortComp(vector<int> &arr, long long &comparisons);

void ShakerSortTime(vector<int> &arr, double &time);
void FlashSortTime(vector<int> &arr, double &time);

//* Vy's part
void SelectionSortComp(vector<int> &arr, long long &comparisons);
void InsertionSortComp(vector<int> &arr, long long &comparisons);
void BubbleSortComp(vector<int> &arr, long long &comparisons);

void SelectionSortTime(vector<int> &arr, double &time);
void InsertionSortTime(vector<int> &arr, double &time);
void BubbleSortTime(vector<int> &arr, double &time);

//* Global variables
// Supported algorithms
const vector<string> Algo = {"Bubble Sort",
                             "Counting Sort",
                             "Flash Sort",
                             "Heap Sort",
                             "Insertion Sort",
                             "Merge Sort",
                             "Quick Sort",
                             "Radix Sort",
                             "Selection Sort",
                             "Shaker Sort",
                             "Shell Sort"};

// Function pointer for comparing
const vector<MeasureComp> Algo_Measuring_Comp = {
    BubbleSortComp,
    CountingSortComp,
    FlashSortComp,
    HeapSortComp,
    InsertionSortComp,
    MergeSortComp,
    QuickSortComp,
    RadixSortComp,
    SelectionSortComp,
    ShakerSortComp,
    ShellSortComp,
};

// Function pointer for measuring time
const vector<MeasureTime> Algo_Measuring_Time = {
    BubbleSortTime,
    CountingSortTime,
    FlashSortTime,
    HeapSortTime,
    InsertionSortTime,
    MergeSortTime,
    QuickSortTime,
    RadixSortTime,
    SelectionSortTime,
    ShakerSortTime,
    ShellSortTime,
};
