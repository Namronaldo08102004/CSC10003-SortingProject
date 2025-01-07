#include "../Header_Files/All.h"

vector<int> arr2Vec(int *arr, int n)
{
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        vec[i] = arr[i];
    return vec;
}

int SearchAlgorithm(vector<string> Algo, string target)
{
    int left = 0;
    int right = Algo.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (Algo[mid] == target) //Seeked
            return mid;
        else if (Algo[mid] < target) //Continue to search in right side
            left = mid + 1;
        else //Continue to search in left side
            right = mid - 1;
    }

    return -1;
}

bool isNum(char *str) // check if the string is a number
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] < '0' || '9' > str[i])
            return false;
    return true;
}

string title(char *str) // convert the string to title format
{
    string s = str;
    s[0] -= 32;
    size_t found = s.find("-");

    while (found != string::npos)
    {
        s[found] = ' ';
        if (found + 1 < s.length())
            s[found + 1] -= 32;
        found = s.find('-', found + 1);
    }
    return s;
}

bool supportAlgorithm(string algo) // Check if the algorithm is supported or not
{
    for (int i = 0; i < Algo.size(); i++)
        if (algo == Algo[i])
            return true;
    return false;
}
bool checkVailidity(Task task)
{
    if (!supportAlgorithm(task.al1)) // If the algorithm is not supported
    {
        cout << "\nAlgorithm " << task.al1 << " is not supported!\n";
        return false;
    }
    else if (task.mode == "-c" && !supportAlgorithm(task.al2)) // In comparison mode, if the algorithm 2 is not supported
    {
        cout << "\nAlgorithm " << task.al2 << " is not supported!\n";
        return false;
    }

    if ((task.command == 1 || task.command == 3) && task.outPara != "-time" && task.outPara != "-comp" && task.outPara != "-both")
    {
        cout << "\nWrong output parameter!!!\n"; // Wrong output parameter
        return false;
    }
    if ((task.command == 2 || task.command == 5) && task.inOrder != "-rand" && task.inOrder != "-nsorted" && task.inOrder != "-sorted" && task.inOrder != "-rev")
    {
        cout << "\nWrong input order!!!\n"; // Wrong input order
        return false;
    }

    return true;
}

bool getInfo4(int argc, char *argv[], Task &task)
{
    task.mode = argv[1]; // Get the mode

    if (task.mode != "-a" && task.mode != "-c") // Wrong format
        return false;

    if (task.mode == "-a")
    {
        task.al1 = title(argv[2]); // Get the algorithm
        task.indexAlgo1 = SearchAlgorithm(Algo, task.al1);
        task.al2 = ""; // No algorithm 2
        task.indexAlgo2 = -1;
        if (argc == 5)
        {
            if (!isNum(argv[3])) // Check for using file or not
            {
                task.command = 1;
                task.useFile = true; // Use file
                task.inFile = argv[3]; // Get the input file
            }
            else
            {
                task.command = 3;
                task.inSize = atoi(argv[3]); // Get the input size
            }
            task.outPara = argv[4];
        }
        else
        {
            task.command = 2;
            task.inSize = atoi(argv[3]); // Get the input size
            task.inOrder = argv[4]; // Get the input order
            task.outPara = argv[5]; // Get the output parameter
        }
    }
    else
    {
        task.al1 = title(argv[2]);
        task.indexAlgo1 = SearchAlgorithm(Algo, task.al1);
        task.al2 = title(argv[3]);
        task.indexAlgo2 = SearchAlgorithm(Algo, task.al2);
        if (argc == 5)
        {
            task.command = 4;
            task.useFile = true; // Use file
            task.inFile = argv[4]; // Get the input file
        }
        else
        {
            task.command = 5; 
            task.inSize = atoi(argv[4]); // Get the input size
            task.inOrder = argv[5]; // Get the input order
        }
    }

    return checkVailidity(task); // Check the validity of the input
}

void printBreakLine()
{
    cout << "-------------------------------------------------\n";
}

void printInputOrder(Task task) // Print the input order
{
    if (task.inOrder == "-rand")
        cout << "Input order: Randomize"
             << "\n";
    else if (task.inOrder == "-nsorted")
        cout << "Input order: Nearly Sorted"
             << "\n";
    else if (task.inOrder == "-sorted")
        cout << "Input order: Sorted"
             << "\n";
    else
        cout << "Input order: Reversed"
             << "\n";
}

void printCmd(Task task) // Print the command
{
    switch (task.command)
    {
    case 1:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printBreakLine();
        break;
    case 2:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printInputOrder(task);
        printBreakLine();
        break;
    case 3:
        cout << "\nALGORITHM MODE\n";
        cout << "Algorithm: " << task.al1 << "\n";
        cout << "Input size: " << task.inSize << "\n\n";
        break;
    case 4:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input file: " << task.inFile << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printBreakLine();
        break;
    case 5:
        cout << "\nCOMPARISON MODE\n";
        cout << "Algorithm: " << task.al1 << " | " << task.al2 << "\n";
        cout << "Input size: " << task.inSize << "\n";
        printInputOrder(task);
        printBreakLine();
        break;
    }
}

// Some secondary functions
void exportArrayToFile(vector<int> arr, string file_output)
{
    // Open file to write
    ofstream ofs;
    ofs.open(file_output);
    if (!ofs.is_open()) // Find not found
    {
        cout << "Error: Cannot open file!"
             << "\n";
        return;
    }

    // Write array into file
    int size = arr.size();
    ofs << size << "\n"; // Write size of array
    for (int i = 0; i < size; ++i) // Write array
        ofs << arr[i] << " ";

    // Close file
    ofs.close();
}

void print2Terminal_a(long long comparisons, double time, string requires)
{
    if (requires == "-time") //Only print time
        cout << "Running time: " << time << " ms"
             << "\n";
    else if (requires == "-comp") //Only print the number of comparisons
        cout << "Comparisons: " << comparisons << "\n";
    else if (requires == "-both") //Print both
    {
        cout << "Running time: " << time << " ms"
             << "\n";
        cout << "Comparisons: " << comparisons << "\n";
    }
    cout << "\n";
}

void print2Terminal_c(long long comparisons_1, long long comparisons_2, double time_1, double time_2)
{
    std::cout << "Running time: " << time_1 << " ms | " << time_2 << " ms" //Compare time
              << "\n";
    std::cout << "Comparisons: " << comparisons_1 << " | " << comparisons_2 //Compare the number of comparisons
              << "\n";
    std::cout << "\n";
}