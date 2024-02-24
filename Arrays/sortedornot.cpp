// LOGIC: TRAVERSE IN THE LINEAR TIME AND FIND OUT NEXT ELEMENT IS GREAATER THAN OR EQUAL IS OR NOT?
// TC : O(N)


#include <bits/stdc++.h>

using namespace std;

bool sortedOrNot(int arr[], int n)
{
    // Brut Force Approach
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{

    int arr[] = {1, 2, 3, 42, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool flag = sortedOrNot(arr, n);

    if (flag)
    {
        cout << "Already Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }

    return 0;
}