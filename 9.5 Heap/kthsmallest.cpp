#include<bits/stdc++.h>

using namespace std;

int kthsmallest(vector<int> &arr, int k)
{
     // Using sorting
        // TC : O(n*logn)
        // sort(arr.begin(), arr.end());
        
        // return arr[k-1];
        
        // Using Heap
        // TC : O(n*logk)
        
        int n = arr.size();
        priority_queue<int> maxHeap;
        
        for(int i = 0; i<n; i++){
            maxHeap.push(arr[i]);
            
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
}
int main() {

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout<<kthsmallest(arr, k)<<endl;

    return 0;
}