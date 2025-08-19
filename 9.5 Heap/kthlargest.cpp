#include<bits/stdc++.h>

using namespace std;

//  int findKthLargest(vector<int>& nums, int k) {
        
//         // O(n * logk)
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>> minHeap;
//         for(int i = 0; i<n; i++)
//         {
//             minHeap.push(nums[i]);

//             if(minHeap.size() > k)
//             {
//                 minHeap.pop();
//             }
//         }
//         return minHeap.top();
//     }

void returnAllklargest(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i<n; i++)
    {
        minHeap.push(arr[i]);

        if(minHeap.size() > k) minHeap.pop();
    }

    while(minHeap.size() > 0)
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    cout<<endl;
}
int main() {

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // cout<<findKthLargest(arr, k)<<endl;
    returnAllklargest(arr, k);

    return 0;
}