#ifndef Library_h
#define Library_h

// Libraries
#include <iostream> // cout
#include <fstream>  // file
#include <string>   // string
#include <cstring>  // strlen
#include <vector>   // array
#include <ctime>    // real-time randomization
#include <cstdlib>  // randomized functions
// #include <cmath>
#include <queue>  // queue
#include <chrono> // measure time

// Namespaces
using namespace std;

// Structures
struct Task
{
    int command;                // 1, 2, 3, 4, 5
    string mode;                // "-a", "-c" for compare or perform algo
    string al1, al2;            // Algorithm mentioned
    int indexAlgo1, indexAlgo2; // Index of each algorithm in Algo array
    string inFile;              // Input file
    string outPara;             // output parameters: "-time", "-comp", "-both"

    bool useFile = false;
    int inSize;
    string inOrder; // "-rand", "-nsorted", "-sorted", "-rev"
};

typedef void (*MeasureComp)(vector<int> &arr, long long &comparisons);
typedef void (*MeasureTime)(vector<int> &arr, double &time);

#endif