#include "../Header_Files/All.h"

int main(int argc, char* argv[])
{
    if (argc > 6 || argc < 5)
    {
        cout << "Wrong format!.\nPlease using one of these:\n";
        cout << "[File] -a [Algorithm] [input file] [Output para]\n";
        cout << "[File] -a [Algorithm] [input size] [input order] [Output para]\n";
        cout << "[File] -a [Algorithm] [input size] [Output para]\n";
        cout << "[File] -c [Algo 1] [Algo 2] [input file]\n";
        cout << "[File] -c [Algo 1] [Algo 2] [input size] [input order]\n";
        return 0;
    }

    Task task;
    bool check = getInfo4(argc, argv, task);
    if (!check)
        return 0; // Return 0 for not raising an error

    switch (task.command)
    {
        case 1:
            Command_1(task);
            break;
        case 2:
            Command_2(task);
            break;
        case 3:
            Command_3(task);
            break;
        case 4:
            Command_4(task);
            break;
        case 5:
            Command_5(task);
            break;
    }

    return 0;
}