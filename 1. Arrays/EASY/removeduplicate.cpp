// Remove Duplicates in inplace from Sorted Array

// Problem statement
// You are given a sorted integer array 'arr' of size 'n'.
// You need to remove the duplicates from the array such that each element appears only once. IN STARTING ITSELF
// Return the length of this new array.

#include <bits/stdc++.h>

using namespace std;

void removeDuplicate(vector<int> &arr, int n)
{
    // // BRUT FORCE APPROACH
    // // USING SET
    // TC: O(N + N*LOGN) SC: O(N)
    // set<int> st;

    // for (auto it : arr) // this will take O(N*logN) time
    // {
    //     st.insert(it);
    // }

    // int index = 0;
    // for (auto it : st) // it will take O(N) time
    // {
    //     arr[index] = it;
    //     index++;
    // }
    // cout << index << " ";

    // total time take by this appraoch = O(N + N*logN)




    // OPTIMAL APPROACH USING 2 POINTER
    //  TIME COMPLEXITY = O(N)
    // SPACE COMPLEXITY = O(1)

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    cout <<( i + 1) << endl;
}
int main()
{

    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};

    int size = arr.size();

    removeDuplicate(arr, size);

    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    return 0;
}