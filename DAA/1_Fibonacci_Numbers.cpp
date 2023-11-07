#include <iostream>
#include <vector>

using namespace std;

// Iteratively using memoization
int iStepFibbonacci(int n)
{
    int prev1 = 1, prev2 = 0;
    if (n <= 1)
    {
        return n;
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = prev1 + prev2;
        cout << temp << " ";
        prev2 = prev1;
        prev1 = temp;
    }
    cout << endl;
    return prev1;
}

int rSteps = 0;

// Recursively
int rStepFibbonacci(int n)
{
    rSteps++;
    if (n <= 1)
        return n;
    return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';
    cout << "Following is the fibonacci series of " << n << "numbers" << endl;
    cout << "nth Fibonacci number is : " << iStepFibbonacci(n) << '\n';
    cout << "Steps required using recursion : " << rSteps << '\n';
    return 0;
}

/*
Recursive fibbonacci:
Time Complexity: O(2^(n-1))
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n)
Auxiliary Space: O(1)
*/