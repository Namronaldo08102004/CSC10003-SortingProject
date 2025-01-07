#include "../Header_Files/All.h"

//? Count comparisons
void ShakerSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int ArraySize = arr.size();
    int left = 0, right = ArraySize - 1;
    while (++comparisons && left < right)
    {
        bool swapped = false;
        for (int i = left; ++comparisons && i < right; i++) // Passing from left, find the max and move to last
            if (++comparisons && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        right--; // Decrement the last pos which is the current max

        for (int i = right; ++comparisons && i > left; i--) // Passing from right, find the min and move to first
            if (++comparisons && arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        left++; // Increment the first pos which is the current min

        if (++comparisons && !swapped) // There is no swap, the array is sorted
            break;
    }
}
//? Measuring time
void ShakerSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int ArraySize = arr.size();
    int left = 0, right = ArraySize - 1;
    while (left < right)
    {
        bool swapped = false;
        for (int i = left; i < right; i++) // Passing from left, find the max and move to last
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        right--; // Decrement the last pos which is the current max

        for (int i = right; i > left; i--) // Passing from right, find the min and move to first
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        left++; // Increment the first pos which is the current min

        if (!swapped) // There is no swap, the array is sorted
            break;
    }
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}

//? Count comparisons
void InsertionSortVariantComp(vector<int> &arr, int left, int right, long long &comparisons)
{
    for (int i = left + 1; ++comparisons && i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (++comparisons && j >= left && ++comparisons && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}
void FlashSortComp(vector<int> &arr, long long &comparisons)
{
    comparisons = 0;
    int Arraysize = arr.size(); // Get the size of array
    // Get the number of buckets used for this algorithm, 0.45 is the best number for helping algorithm run effectively
    int numBuckets = (int)(0.45 * Arraysize);

    if (++comparisons && numBuckets > 0)
    {
        // Create an array save the position of the last element in each bucket
        int *EndOfBucket = new int[numBuckets];
        for (int i = 0; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] = 0;

        // Find the minimum value and the position of the maximum value in the array
        int minValue = arr[0];
        int indexMax = 0;
        for (int i = 1; ++comparisons && i < Arraysize; ++i)
        {
            if (++comparisons && arr[i] < minValue)
                minValue = arr[i];
            else if (++comparisons && arr[i] > arr[indexMax])
                indexMax = i;
        }

        // Deliver each element into a certain bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            double temp = (double)(numBuckets - 1) / (arr[indexMax] - minValue);
            int indexBucket = (int)(temp * (arr[i] - minValue));
            EndOfBucket[indexBucket]++;
        }

        // Used prefix sum to identify precisely the position of the last element in each bucket
        for (int i = 1; ++comparisons && i < numBuckets; ++i)
            EndOfBucket[i] += EndOfBucket[i - 1];

        // Save the position of each last element in bucket
        vector<int> saveBucketSize;
        for (int i = 0; ++comparisons && i < numBuckets; ++i)
            saveBucketSize.push_back(EndOfBucket[i]);

        // Move the maximum number to the first position
        int temp = arr[indexMax];
        arr[indexMax] = arr[0];
        arr[0] = temp;

        // Move each element to exact bucket
        for (int i = 0; ++comparisons && i < Arraysize; ++i)
        {
            double tempValue = (double)(numBuckets - 1) / (temp - minValue);
            int indexBucket = (int)(tempValue * (arr[0] - minValue));
            swap(arr[0], arr[EndOfBucket[indexBucket] - 1]);

            EndOfBucket[indexBucket]--;
            if (++comparisons && EndOfBucket[0] == 0)
                break;
        }

        delete[] EndOfBucket; // Deallocation

        for (int i = 0; ++comparisons && i < numBuckets; ++i)
        {
            if (++comparisons && i == 0)
                InsertionSortVariantComp(arr, 0, saveBucketSize[i] - 1, comparisons);
            else
                InsertionSortVariantComp(arr, saveBucketSize[i - 1], saveBucketSize[i] - 1, comparisons);
        }
    }
    else
        InsertionSortVariantComp(arr, 0, arr.size() - 1, comparisons);
}
//? Measuring time
void InsertionSortVariantTime(vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) // Move the other elements
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place it in the correct position
    }
}
void FlashSortTime(vector<int> &arr, double &time)
{
    auto startTime = chrono::high_resolution_clock::now();
    int Arraysize = arr.size(); // Get the size of array
    // Get the number of buckets used for this algorithm, 0.45 is the best number for helping algorithm run effectively
    int numBuckets = (int)(0.45 * Arraysize);

    if (numBuckets > 0)
    {
        // Create an array save the position of the last element in each bucket
        int *EndOfBucket = new int[numBuckets];
        for (int i = 0; i < numBuckets; ++i)
            EndOfBucket[i] = 0;

        // Find the minimum value and the position of the maximum value in the array
        int minValue = arr[0];
        int indexMax = 0;
        for (int i = 1; i < Arraysize; ++i)
        {
            if (arr[i] < minValue)
                minValue = arr[i];
            else if (arr[i] > arr[indexMax])
                indexMax = i;
        }

        // Deliver each element into a certain bucket
        for (int i = 0; i < Arraysize; ++i)
        {
            double temp = (double)(numBuckets - 1) / (arr[indexMax] - minValue);
            int indexBucket = (int)(temp * (arr[i] - minValue));
            EndOfBucket[indexBucket]++;
        }

        // Used prefix sum to identify precisely the position of the last element in each bucket
        for (int i = 1; i < numBuckets; ++i)
            EndOfBucket[i] += EndOfBucket[i - 1];

        // Save the position of each last element in bucket
        vector<int> saveBucketSize;
        for (int i = 0; i < numBuckets; ++i)
            saveBucketSize.push_back(EndOfBucket[i]);

        // Move the maximum number to the first position
        int temp = arr[indexMax];
        arr[indexMax] = arr[0];
        arr[0] = temp;

        // Move each element to exact bucket
        for (int i = 0; i < Arraysize; ++i)
        {
            double tempValue = (double)(numBuckets - 1) / (temp - minValue);
            int indexBucket = (int)(tempValue * (arr[0] - minValue));
            swap(arr[0], arr[EndOfBucket[indexBucket] - 1]);

            EndOfBucket[indexBucket]--;
            if (EndOfBucket[0] == 0)
                break;
        }

        delete[] EndOfBucket; // Deallocation

        for (int i = 0; i < numBuckets; ++i)
        {
            if (i == 0)
                InsertionSortVariantTime(arr, 0, saveBucketSize[i] - 1);
            else
                InsertionSortVariantTime(arr, saveBucketSize[i - 1], saveBucketSize[i] - 1);
        }
    }
    else
        InsertionSortVariantTime(arr, 0, arr.size() - 1);
    auto endTime = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = endTime - startTime;
    time = duration.count();
}