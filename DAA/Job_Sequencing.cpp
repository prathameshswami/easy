#include <algorithm>
#include <iostream>
using namespace std;

struct Job
{
    char id;  // Job Id
    int dead; // Deadline of job
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n];  // To keep track of free time slots

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    int profitEarned = 0;
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
        if (slot[i])
        {
            cout << arr[result[i]].profit << " ";
            profitEarned += arr[result[i]].profit;
        }

    cout << endl;

    cout << "The Maximum Profit Earned is :- " << profitEarned << endl;
}

int main()
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";

    printJobScheduling(arr, n);
    return 0;
}
