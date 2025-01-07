#include "../Header_Files/All.h"

void Command_4(Task task)
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
    vector<int> first_arr = vector<int>(size);
    for (int i = 0; i < size; ++i)
        ifs >> first_arr[i];

    // Close file
    ifs.close();
    vector<int> second_arr = vector<int>(first_arr);

    // Print some initial information to console screen
    task.inSize = size;
    printCmd(task);

    // Measure time - comparisons
    long long comparisons_1 = 0;
    double time_1 = 0;
    Algo_Measuring_Comp[task.indexAlgo1](first_arr, comparisons_1);
    Algo_Measuring_Time[task.indexAlgo1](first_arr, time_1);
    long long comparisons_2 = 0;
    double time_2 = 0;
    Algo_Measuring_Comp[task.indexAlgo2](second_arr, comparisons_2);
    Algo_Measuring_Time[task.indexAlgo2](second_arr, time_2);

    // Print measured data(s) to console screen
    print2Terminal_c(comparisons_1, comparisons_2, time_1, time_2);
}