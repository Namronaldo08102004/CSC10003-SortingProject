#include "../Header_Files/All.h"

//? Count comparisons
int findMedianComp(vector<int> &arr, int left, int right, long long &comparisons)
{
    int mid = left + (right - left) / 2;

    // Sort the three elements
    if (++comparisons && arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);
    if (++comparisons && arr[mid] > arr[right]) // Swap the mid and last elements
        swap(arr[mid], arr[right]);
    if (++comparisons && arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);

    return mid;
}
int partitionComp(vector<int> &arr, int left, int right, long long &comparisons)
{
    int pIndex = findMedianComp(arr, left, right, comparisons); // Find the median of the first, mid, last elements
    int pivot = arr[pIndex];
    swap(arr[pIndex], arr[left]); // Switch it back to the first element

    int i = left + 1;
    for (int j = i; ++comparisons && j <= right; j++) // Move the elements smaller than pivot to the left
    {
        if (++comparisons && arr[j] < pivot)
            swap(arr[j], arr[i++]);
    }
    swap(arr[i - 1], arr[left]); // Switch the pivot to its position
    return i - 1;
}
void Quick_Sort_Comp(vector<int> &arr, int left, int right, long long &comparisons)
{
    if (++comparisons && left < right)
    {
        int p = partitionComp(arr, left, right, comparisons); // Find the pivot
        Quick_Sort_Comp(arr, left, p - 1, comparisons);       // Sort the left part
        Quick_Sort_Comp(arr, p + 1, right, comparisons);      // Sort the right part
    }
}
void QuickSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    Quick_Sort_Comp(arr, 0, arr.size() - 1, comparisons);
}
//? Measuring time
int findMedianTime(vector<int> &arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    // Sort the three elements
    if (arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);
    if (arr[mid] > arr[right]) // Swap the mid and last elements
        swap(arr[mid], arr[right]);
    if (arr[left] > arr[mid]) // Swap the first and mid elements
        swap(arr[left], arr[mid]);

    return mid;
}
int partitionTime(vector<int> &arr, int left, int right)
{
    int pIndex = findMedianTime(arr, left, right); // Find the median of the first, mid, last elements
    int pivot = arr[pIndex];
    swap(arr[pIndex], arr[left]); // Switch it back to the first element

    int i = left + 1;
    for (int j = i; j <= right; j++) // Move the elements smaller than pivot to the left
    {
        if (arr[j] < pivot)
            swap(arr[j], arr[i++]);
    }
    swap(arr[i - 1], arr[left]); // Switch the pivot to its position
    return i - 1;
}
void Quick_Sort_Time(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int p = partitionTime(arr, left, right); // Find the pivot
        Quick_Sort_Time(arr, left, p - 1);       // Sort the left part
        Quick_Sort_Time(arr, p + 1, right);      // Sort the right part
    }
}
void QuickSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    Quick_Sort_Time(arr, 0, arr.size() - 1);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void ShellSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int n = arr.size();
    int gap = 1;
    while (++comparisons && gap < n / 3) // generate the gap using Knuth's formula
        gap = gap * 3 + 1;
    // Other: Sedgewick sequence (4^i + 3 * 2^(i - 1) + 1), Hibbard sequence (2^k - 1)

    while (++comparisons && gap > 0)
    {
        for (int i = gap; ++comparisons && i < n; i++)
        {
            int tmp = arr[i];
            int j = i;
            while ((++comparisons && j >= gap) && (++comparisons && arr[j - gap] > tmp)) // Insertion sort within the gap
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
        gap /= 3; // Reduce the gap follows above generated formula
    }
}
//? Measuring time
void ShellSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int n = arr.size();
    int gap = 1;
    while (gap < n / 3) // generate the gap using Knuth's formula
        gap = gap * 3 + 1;
    // Other: Sedgewick sequence (4^i + 3 * 2^(i - 1) + 1), Hibbard sequence (2^k - 1)

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > tmp) // Insertion sort within the gap
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
        gap /= 3; // Reduce the gap follows above generated formula
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void CountingSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int n = arr.size();
    int Min = arr[0], Max = arr[0];
    for (auto x : arr)
    {
        if (++comparisons && x < Min)
            Min = x;
        if (++comparisons && x > Max)
            Max = x;
    }

    int range = Max - Min + 1;
    vector<int> count(range, 0);
    for (auto x : arr)
        count[x - Min]++;

    int ind = 0;
    for (auto x : count)
    {
        while (++comparisons && x--)
            arr[ind++] = Min;
        Min++;
    }
}
//? Measuring time
void CountingSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int n = arr.size();
    int Min = arr[0], Max = arr[0];
    for (auto x : arr)
    {
        if (x < Min)
            Min = x;
        if (x > Max)
            Max = x;
    }

    int range = Max - Min + 1;
    vector<int> count(range, 0);
    for (auto x : arr)
        count[x - Min]++;

    int ind = 0;
    for (auto x : count)
    {
        while (x--)
            arr[ind++] = Min;
        Min++;
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}
