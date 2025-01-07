#include "../Header_Files/All.h"

//? Count comparisons
void heapifyComp(vector<int> &arr, int size, int pos, long long &comparisons)
{
    int v = arr[pos];
    bool isHeap = false;
    while (++comparisons && (!isHeap && 2 * pos + 1 < size))
    {
        int j = 2 * pos + 1;
        if (++comparisons && j < size - 1 && arr[j] < arr[j + 1]) // Get the bigger child node
            j++;
        if (++comparisons && arr[pos] >= arr[j]) // Already satisfied a heap at that element to the rest on the right
            isHeap = true;
        else
        {
            swap(arr[pos], arr[j]); // Reposition the node
            pos = j;                     // Loop to check validity of the node just has swapped
        }
    }
    arr[pos] = v;
}
void HeapSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    for (int i = arr.size() / 2 - 1; ++comparisons && i >= 0; i--) // Loop from the middle to heapify the whole array
        heapifyComp(arr, arr.size(), i, comparisons);
    for (int i = arr.size() - 1; ++comparisons && i > 0; i--)
    {
        swap(arr[0], arr[i]);           // Swap the first element with the last unsorted element
        heapifyComp(arr, i, 0, comparisons); // Heapify the semi-heap again with the reduced size
    }
}
//? Measuring time
void heapifyTime(vector<int> &arr, int size, int pos)
{
    int v = arr[pos];
    bool isHeap = false;
    while (!isHeap && 2 * pos + 1 < size)
    {
        int j = 2 * pos + 1;
        if (j < size - 1 && arr[j] < arr[j + 1]) // Get the bigger child node
            j++;
        if (arr[pos] >= arr[j]) // Already satisfied a heap at that element to the rest on the right
            isHeap = true;
        else
        {
            swap(arr[pos], arr[j]); // Reposition the node
            pos = j;                     // Loop to check validity of the node just has swapped
        }
    }
    arr[pos] = v;
}
void HeapSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    for (int i = arr.size() / 2 - 1; i >= 0; i--) // Loop from the middle to heapify the whole array
        heapifyTime(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Swap the first element with the last unsorted element
        heapifyTime(arr, i, 0);    // Heapify the semi-heap again with the reduced size
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void mergeComp(vector<int> &arr, int left, int mid, int right, long long &comparisons)
{
    int *tmp_arr = new int[right - left + 1]; // Create a temporary array
    int i = left, j = mid + 1, k = 0;

    while (++comparisons && (i <= mid && j <= right))
    {
        if (++comparisons && (arr[i] < arr[j])) // Comparing element ant index i, j of the 2 small array, put it accordingly into the tmp list
            tmp_arr[k++] = arr[i++];
        else
        {
            tmp_arr[k++] = arr[j++];
            ++comparisons;
        }
    }
    while (++comparisons && i <= mid) // Put the rest of the 2 list into the tmp
        tmp_arr[k++] = arr[i++];
    while (++comparisons && j <= right)
        tmp_arr[k++] = arr[j++];
    for (int i = left, k = 0; ++comparisons && i <= right; i++, k++) // Copy back element to the original array
        arr[i] = tmp_arr[k];
    delete[] tmp_arr;
}
void Merge_Sort_Comp(vector<int> &arr, int left, int right, long long &comparisons)
{
    if (++comparisons && (left < right))
    {
        int mid = left + (right - left) / 2;          // get the mid, avoiding overflowing
        Merge_Sort_Comp(arr, left, mid, comparisons); // Recursively divide into small lists
        Merge_Sort_Comp(arr, mid + 1, right, comparisons);
        mergeComp(arr, left, mid, right, comparisons); // Merge the sorted lists together
    }
}
void MergeSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    Merge_Sort_Comp(arr, 0, arr.size() - 1, comparisons);
}
//? Measuring time
void mergeTime(vector<int> &arr, int left, int mid, int right)
{
    int *tmp_arr = new int[right - left + 1]; // Create a temporary array
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if ((arr[i] < arr[j])) // Comparing element ant index i, j of the 2 small array, put it accordingly into the tmp list
            tmp_arr[k++] = arr[i++];
        else
            tmp_arr[k++] = arr[j++];
    }
    while (i <= mid) // Put the rest of the 2 list into the tmp
        tmp_arr[k++] = arr[i++];
    while (j <= right)
        tmp_arr[k++] = arr[j++];
    for (int i = left, k = 0; i <= right; i++, k++) // Copy back element to the original array
        arr[i] = tmp_arr[k];
    delete[] tmp_arr;
}
void Merge_Sort_Time(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // get the mid, avoiding overflowing
        Merge_Sort_Time(arr, left, mid);     // Recursively divide into small lists
        Merge_Sort_Time(arr, mid + 1, right);
        mergeTime(arr, left, mid, right); // Merge the sorted lists together
    }
}
void MergeSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    Merge_Sort_Time(arr, 0, arr.size() - 1);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void RadixSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    queue<int> *bucket = new queue<int>[10];
    int longest = 0;
    int minVal = arr[0];
    bool negative = false;

    for (int i = 0; ++comparisons && i < arr.size(); i++)
        if (++comparisons && arr[i] < 0)
        {
            negative = true;                   // Check for negative numbers
            minVal = min(minVal, arr[i]); // Get the minimum value of the array
        }

    if (++comparisons && negative)
        for (int i = 0; ++comparisons && i < arr.size(); i++)
            arr[i] -= minVal; // Add every element up to 0

    for (int i = 0; ++comparisons && i < arr.size(); i++)
        longest = max(longest, int(to_string(arr[i]).size())); // Get the max size of the elements

    int expo = 1;
    while (++comparisons && longest--)
    {
        for (int i = 0; ++comparisons && i < arr.size(); i++)
        {
            int order = (arr[i] / expo) % 10; // Get the digit from rightmost to leftmost
            bucket[order].push(arr[i]);       // Push into a queue
        }
        expo *= 10;

        for (int i = 0, k = 0; ++comparisons && i < 10; i++)
            while (++comparisons && !bucket[i].empty()) // Pop the element gradually and copy back to the array
            {
                arr[k++] = bucket[i].front();
                bucket[i].pop();
            }
    }

    if (++comparisons && negative) // Decrement back to its original
        for (int i = 0; ++comparisons && i < arr.size(); i++)
            arr[i] += minVal;

    delete[] bucket;
}
//? Measuring time
void RadixSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();

    queue<int> *bucket = new queue<int>[10];
    int longest = 0;
    int minVal = arr[0];
    bool negative = false;

    for (int i = 0; i < arr.size(); i++)
        if (arr[i] < 0)
        {
            negative = true;                   // Check for negative numbers
            minVal = min(minVal, arr[i]); // Get the minimum value of the array
        }

    if (negative)
        for (int i = 0; i < arr.size(); i++)
            arr[i] -= minVal; // Add every element up to 0

    for (int i = 0; i < arr.size(); i++)
        longest = max(longest, int(to_string(arr[i]).size())); // Get the max size of the elements

    int expo = 1;
    while (longest--)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int order = (arr[i] / expo) % 10; // Get the digit from rightmost to leftmost
            bucket[order].push(arr[i]);       // Push into a queue
        }
        expo *= 10;

        for (int i = 0, k = 0; i < 10; i++)
            while (!bucket[i].empty()) // Pop the element gradually and copy back to the array
            {
                arr[k++] = bucket[i].front();
                bucket[i].pop();
            }
    }

    if (negative) // Decrement back to its original
        for (int i = 0; i < arr.size(); i++)
            arr[i] += minVal;

    delete[] bucket;
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}
