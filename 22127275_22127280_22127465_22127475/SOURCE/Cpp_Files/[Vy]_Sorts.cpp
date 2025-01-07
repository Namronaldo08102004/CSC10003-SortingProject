#include "../Header_Files/All.h"

//? Count comparisons
void SelectionSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int n = arr.size();
    for (int i = 0; ++comparisons && i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; ++comparisons && j < n; j++) // Find the min element's index
            if (++comparisons && arr[j] < arr[minInd])
                minInd = j;

        if (++comparisons && minInd != i) // Swap the min to its pos if the min's index different from the current
            std::swap(arr[minInd], arr[i]);
    }
}
//? Measuring time
void SelectionSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++) // Find the min element's index
            if (arr[j] < arr[minInd])
                minInd = j;

        if (minInd != i) // Swap the min to its pos if the min's index different from the current
            std::swap(arr[minInd], arr[i]);
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void InsertionSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int n = arr.size();
    for (int i = 1; ++comparisons && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (++comparisons && j >= 0 && ++comparisons && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}
//? Measuring time
void InsertionSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void BubbleSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int n = arr.size();
    for (int i = 0; ++comparisons && i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; ++comparisons && j < n - i - 1; j++) // Move the largest to last
            if (++comparisons && arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (++comparisons && !swapped) // If there is no swap, the array is sorted
            break;
    }
}
//? Measuring time
void BubbleSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) // Move the largest to last
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        if (!swapped) // If there is no swap, the array is sorted
            break;
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}
