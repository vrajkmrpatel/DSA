

#include <bits/stdc++.h>

using namespace std;

void sortArray(vector<int> &arr, int n)
{

    // BRUT FORCE
    // time - O(N*logN) like merge sort
    // space - O(N)
    // sort(arr.begin(), arr.end());

    // Better solution

    // int count_0 = 0;
    // int count_1 = 0;
    // int count_2 = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //         count_0++;
    //     else if (arr[i] == 1)
    //         count_1++;
    //     else
    //         count_2++;
    // }

    // for (int i = 0; i < count_0; i++)
    //     arr[i] = 0;
    // for (int i = count_0; i < count_0 + count_1; i++)
    //     arr[i] = 1;
    // for (int i = count_0 + count_1; i < n; i++)
    //     arr[i] = 2;

    // OPTIMAL APPROACH - Dutch National Flag Algorithm
    // Time - O(N)
    // space - O(1)
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {

        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}