#include <bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> &A)
{

    // ONLY OPTIMAL SOLUTION EXIST

    // 1) FIND OUT BREAK POINT
    int n = A.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }

    // 2) SMALLEST ELE IN REMAINING ARRAY GREATER THAN ind

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    // 3) REVERSE THE REMAINING ELEMENTS

    reverse(A.begin() + ind + 1, A.end());

    return A;
}
int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    // sort(arr.begin(), arr.end(), greater<int>());
    // sort(arr.rbegin(), arr.rend());
    // nextPermutation(arr);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}