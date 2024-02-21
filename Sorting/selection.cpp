// LOGIC: TAKE MINIMUM ELEMENT AND SWAP IT WITH FIRST ELEMENT 
// IN FIRST PASS WE GET SMALLEST ELEMENT AT THE FIRST 
// THE SORTED ARRAY IS MAINTAINED AT THE FIRST

#include <bits/stdc++.h>

using namespace std;

// void selectionSort(int a[], int n)
// {
//     int min_index;
//     for (int i = 0; i < n - 1; i++)
//     {
//         min_index = i;

//         for (int j = i + 1; j < n; j++)
//         {

//             if (a[j] < a[min_index])
//             {
//                 min_index = j;
//             }
//         }
//         swap(a[i], a[min_index]);
//     }
// }

void selectionSort(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int min_index;

    for (int i = 0; i < n - 1; i++)
    {

        min_index = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    // Using Array
    // int arr[] = {13, 46, 24, 52, 9};

    // int n = sizeof(arr) / sizeof(arr[0]);

    // selectionSort(arr, n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // Using Vector

    vector<int> v = {13, 46, 24, 52, 9};

    selectionSort(v);

    for(auto it: v){
        cout<< it<<" ";
    }
    return 0;
}