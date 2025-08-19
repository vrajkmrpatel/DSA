// Problem statement
// Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping the non-zero elements at the start of the array in their original order. Return the modified array.

#include <bits/stdc++.h>

using namespace std;

void moveAllZeros(vector<int> &arr, int n)
{

    // // BRUT FORCE APPROACH
    // // LOGIC:
    // vector<int> temp;

    // // STEP 1: TC: O(N)
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }

    // // STEP 2: TC: O(X) WHERE X IS NUMBER OF NON ZERO VALUES
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     arr[i] = temp[i];
    // }

    // int nonZero = temp.size();

    // // STEP 3: TC: O(N - X)
    // for (int i = nonZero; i < n; i++)
    // {
    //     arr[i] = 0;
    // }

    // TOTAL TC: O(2N)

    // OPTIMAL ONE
    // TC: O(N)
    // EVERY TIME I WILL BE ON 0 ELEMENT
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i++], arr[j]);
        }
    }
}

int main()
{

    vector<int> arr = {1, 2, 0, 1, 0, 2, 3, 0, 0, 0, 0, 0, 4};
    int n = arr.size();
    // cout << n << " ";

    moveAllZeros(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}