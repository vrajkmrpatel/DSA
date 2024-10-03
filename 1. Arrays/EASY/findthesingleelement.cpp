#include <bits/stdc++.h>

using namespace std;

int singleElement(vector<int> &arr)
{
    int n = arr.size();
    // Brut force
    //  O(N) time complexity
    //   for(int i  =0;  i<arr.size(); i = i+2){

    // 	if(arr[i] != arr[i+1]){
    // 		return arr[i];
    // 	}
    // }

    // implementing using stack
    /*
    Time Complexity: O(N)

    Space Complexity: O(1)

    Where 'N' is the number of elements in the array 'Arr'.
    */
    // Creating an empty stack named, 'St'.
    // stack<int> st;

    // // Traversing through the array.
    // for (int i = 0; i < n; ++i)
    // {
    //     if (st.empty() || st.top() != arr[i])
    //         st.push(arr[i]);
    //     else
    //         st.pop();
    // }
    // return st.top();

    // XOR METHOD BITWISE OPERATOR ^
    // Lets say, ‘arr’ = {1, 1, 2, 3, 3}, then we have 1 ^ 1 ^ 2 ^ 3 ^ 3 = (1 ^ 1) ^ 2 ^ (3 ^ 3) = 0 ^ 2 ^ 0  = 2, where ‘^’ denotes the bitwise XOR operation.
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
    }
    return xr;

    
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};

    int ans = singleElement(arr);
    cout << ans;
    return 0;
}