#include <bits/stdc++.h>

using namespace std;

// rotate in left by 1
// vector<int> rotateArray(vector<int> &arr, int n)
// {
//     // Write your code here.
//     int left = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//     arr[n - 1] = left;
//     return arr;
// }

void rotateByD(int arr[], int d, int n)
{
    // Normal approach Not wording in GFG
    // while (d--)
    // {
    //     int temp = arr[n - 1];
    //     for (int i = n - 1; i > 0; i--)
    //     {
    //         arr[i] = arr[i - 1];
    //     }
    //     arr[0] = temp;
    // }

    // BRUT FORCE APPROACH
    // d = d % n;
    // int temp[d];
    // for (int i = 0; i < d; i++) // O(D) TIME
    // {
    //     temp[i] = arr[i];
    // }

    // for (int i = d; i < n; i++) // O(N - D) TIME
    // {
    //     arr[i - d] = arr[i];
    // }

    // for (int i = n - d; i < n; i++) // O(D) time
    // {
    //     arr[i] = temp[i - (n - d)];
    // }

    // total time: O(N + D);
    // space time: O(D) We are using extra temp array of size D

    // Optimal Approach
    // LOGIC: USING REVERSE APPROACH

    // FIRST REVERSE THE FIRST D ELEMENTS IN the ARRAY
    reverse(arr, arr + d); // O(D)

    // Reverse the remaining N - D elements
    reverse(arr + d, arr + n); // O(N-D)

    // Reverse the whole the array
    reverse(arr, arr + n); // O(N)

    // TOTAL TC: O(2*N)
    // SPACE COMP: O(1) NO EXTRA SPACE IS USED.
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int d = 12;

    int n = sizeof(arr) / sizeof(arr[0]);

    rotateByD(arr, d, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
