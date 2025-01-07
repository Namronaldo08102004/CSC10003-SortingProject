#include "../Header_Files/All.h"

void Command_5(Task task)
{
    string sortAlgoNo1 = task.al1;
    string sortAlgoNo2 = task.al2;

    int size = task.inSize;
    vector<int> arr1(size);

    if (task.inOrder == "-rand")
        GenerateRandomData(&arr1[0], size);
    else if (task.inOrder == "-sorted")
        GenerateSortedData(&arr1[0], size);
    else if (task.inOrder == "-nsorted")
        GenerateNearlySortedData(&arr1[0], size);
    else
        GenerateReverseData(&arr1[0], size);
    vector<int> arr2 = vector<int>(arr1);

    exportArrayToFile(arr1, "input.txt");

    // Print some initial information to console screen
    printCmd(task);

    // comparison
    long long comparisons_1 = 0;
    double time_1 = 0.0;
    Algo_Measuring_Comp[task.indexAlgo1](arr1, comparisons_1);
    Algo_Measuring_Time[task.indexAlgo1](arr1, time_1);
    long long comparisons_2 = 0;
    double time_2 = 0.0;
    Algo_Measuring_Comp[task.indexAlgo1](arr2, comparisons_2);
    Algo_Measuring_Time[task.indexAlgo1](arr2, time_2);

    print2Terminal_c(comparisons_1, comparisons_2, time_1, time_2);
}
