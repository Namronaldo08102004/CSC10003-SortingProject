#include "../Header_Files/All.h"

// Handle Command 1
void Command_1(Task task)
{
    // Open file to read
    ifstream ifs;
    ifs.open(task.inFile);
    if (!ifs.is_open())
    {
        cout << "Error: Cannot open file!"
             << "\n";
        return;
    }

    // Read size of array
    int size;
    ifs >> size;

    // Read array
    vector<int> arr = vector<int>(size);
    for (int i = 0; i < size; ++i)
        ifs >> arr[i];

    // Close file
    ifs.close();

    // Print some initial information to console screen
    task.inSize = size;
    printCmd(task);

    // Measure time - comparisons
    long long comparisons = 0;
    double time = 0;
    Algo_Measuring_Comp[task.indexAlgo1](arr, comparisons);
    Algo_Measuring_Time[task.indexAlgo1](arr, time);

    // Print measured data(s) to console screen
    print2Terminal_a(comparisons, time, task.outPara);

    // Export array
    exportArrayToFile(arr, "output.txt");
}

// Handle Command 3
void Command_3(Task task)
{
    // Generate four types of array
    vector<int> arr_1 = vector<int>(task.inSize);
    GenerateData(&arr_1[0], task.inSize, 0);
    vector<int> arr_2 = vector<int>(task.inSize);
    GenerateData(&arr_2[0], task.inSize, 3);
    vector<int> arr_3 = vector<int>(task.inSize);
    GenerateData(&arr_3[0], task.inSize, 1);
    vector<int> arr_4 = vector<int>(task.inSize);
    GenerateData(&arr_4[0], task.inSize, 2);

    // Export arrays into 4 files
    exportArrayToFile(arr_1, "input_1.txt");
    exportArrayToFile(arr_2, "input_2.txt");
    exportArrayToFile(arr_3, "input_3.txt");
    exportArrayToFile(arr_4, "input_4.txt");

    // Print some initial information to console screen
    printCmd(task);

    // Randomed array
    cout << "Input order: Randomize"
         << "\n";
    printBreakLine();
    // Measure time - comparisons
    long long comparisons_1 = 0;
    double time_1 = 0;
    Algo_Measuring_Comp[task.indexAlgo1](arr_1, comparisons_1);
    Algo_Measuring_Time[task.indexAlgo1](arr_1, time_1);
    // Print measured data(s) to console screen
    print2Terminal_a(comparisons_1, time_1, task.outPara);

    // Nearly sorted array
    cout << "Input order: Nearly Sorted"
         << "\n";
    printBreakLine();
    // Measure time - comparisons
    long long comparisons_2 = 0;
    double time_2 = 0;
    Algo_Measuring_Comp[task.indexAlgo1](arr_2, comparisons_2);
    Algo_Measuring_Time[task.indexAlgo1](arr_2, time_2);
    // Print measured data(s) to console screen
    print2Terminal_a(comparisons_2, time_2, task.outPara);

    // Sorted array
    cout << "Input order: Sorted"
         << "\n";
    printBreakLine();
    // Measure time - comparisons
    long long comparisons_3 = 0;
    double time_3 = 0;
    Algo_Measuring_Comp[task.indexAlgo1](arr_3, comparisons_3);
    Algo_Measuring_Time[task.indexAlgo1](arr_3, time_3);
    // Print measured data(s) to console screen
    print2Terminal_a(comparisons_3, time_3, task.outPara);

    // Reverse array
    cout << "Input order: Reversed"
         << "\n";
    printBreakLine();
    // Measure time - comparisons
    long long comparisons_4 = 0;
    double time_4 = 0;
    Algo_Measuring_Comp[task.indexAlgo1](arr_4, comparisons_4);
    Algo_Measuring_Time[task.indexAlgo1](arr_4, time_4);
    // Print measured data(s) to console screen
    print2Terminal_a(comparisons_4, time_4, task.outPara);
}