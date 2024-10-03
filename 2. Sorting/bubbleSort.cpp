// LOGIC: IN EVERY PASS WE TAKE MAXIMUM ELEMENT AT THE END
// THE SORTED ARRAY IS MAINTAINED AT THE END

#include <bits/stdc++.h>

using namespace std;

// WORST CASE TIME COMPLEXITY = O(N^2)

// BUT IF THERE IS A SORTED ARRAY ALREADY THEN BEST CASE HAPPENS BECAUSE OF NO SWAPS DIRECTLY RETURN
// TC = O(N) LINEAR TIME COMPLEXITY

void bubbleSort(int a[], int n)
{
    int didSwap = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                didSwap += 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
        cout << "runs\n";
    }
}

int main()
{
    // Using Array
    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Using Vector

    // vector<int> v = {13, 46, 24, 52, 9};

    // // bubbleSort(v);

    // for(auto it: v){
    //     cout<< it<<" ";
    // }
    return 0;
}