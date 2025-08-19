#include<bits/stdc++.h>

using namespace std;

void nearlySorted(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minheap;

    for(int i = 0; i<k; i++)
    {
        minheap.push(arr[i]);
    }

    int i;
    for(i = k; i<arr.size(); i++)
    {
        minheap.push(arr[i]);

        arr[i-k] = minheap.top();
        minheap.pop();
    }

    while(!minheap.empty())
    {
        arr[i-k] = minheap.top();
        minheap.pop();
        i++;
    }
}

int main() {

    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    cout<<endl;
    return 0;
}