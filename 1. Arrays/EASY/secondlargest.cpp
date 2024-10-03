#include <bits/stdc++.h>

using namespace std;

int secondLargest(vector<int> v, int n)
{
    // Brut Force Aproach
    // Total time: O(NlogN) + O(N)

    sort(v.begin(), v.end()); // takes O(NlogN) time

    int largest = v[n - 1];
    for (int i = n - 2; i >= 0; i--) // loop takes O(N) time in worst case
    {

        if (v[i] != largest)
        {
            return v[i];
            break;
        }
    }

    // Better Aproach
    // Total time: O(N) + O(N) = O(2*N)

    // int largest = v[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (v[i] > largest)
    //     {
    //         largest = v[i];
    //     }
    // }

    // cout << largest << " ";

    // int slargest = -1;

    // for (int i = 0; i < n; i++)
    // {
    //     if (v[i] > slargest && v[i] != largest)
    //     {
    //         slargest = v[i];
    //     }
    // }
    // return slargest;

    // Optimal Aproach
    //  Total time: O(N)

    // int largest = v[0];
    // int slargest = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     if (v[i] > largest)
    //     {
    //         slargest = largest;
    //         largest = v[i];
    //     }
    //     else if (v[i] > slargest && v[i] < largest)
    //     {
    //         slargest = v[i];
    //     }
    // }
    // return slargest;
}
int secondSmallest(vector<int> v, int n)
{
    int smallest = v[0];
    int ssmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        if (v[i] < smallest)
        {
            ssmallest = smallest;
            smallest = v[i];
        }
        else if (v[i] > smallest && v[i] < ssmallest)
        {
            ssmallest = v[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(vector<int> v, int n)
{

    int slargest = secondLargest(v, n);
    int ssmallest = secondSmallest(v, n);
    cout << slargest << " " << ssmallest;
    return {slargest, ssmallest};
}
int main()
{

    vector<int> arr = {12, 35, 1, 10, 54, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    getSecondOrderElements(arr, n);

    return 0;
}