#include <bits/stdc++.h>

using namespace std;

int main()
{

    // vector<int> v;

    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // v.push_back(50);

    // iterator

    // vector<int>::iterator it1 = v.begin();
    // vector<int>::iterator it2 = v.end();

    // it1++;
    // cout << *(it1) << " ";

    // it1 = it1 + 2;
    // cout << *(it1) << " ";
    // cout << endl;

    // cout << v[0] << " " << v.at(0) << " ";

    // cout << v.back() << " ";

    // loops

    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }
    // cout << endl;

    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *(it) << " ";
    // }
    // cout << endl;

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // All loops will print the same
    // 10 20 30 40 50
    // 10 20 30 40 50
    // 10 20 30 40 50

    // erase() function

    // single element deletion
    //  10 20 30 40 50
    // v.erase(v.begin() + 1); // result 10 30 40 50

    // deletion of range of values

    // 10 20 30 40 50
    // v.erase(v.begin() + 1,v.begin()+ 3); //reslult 10 40 50

    // insertion of elements in vector

    // vector<int> v1(2, 100);         //{100,100}
    // v1.insert(v1.begin(), 300);     //{300 100 100}
    // v1.insert(v1.begin() + 1, 200); //{300 200 100 100}

    // cout << v1.size()<<endl;

    // for (auto it : v1)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // LISTS

    // dequeue

    // stack
    // stack<int> st;

    // st.push(1);    //{1}
    // st.push(2);    //{2,1}
    // st.push(3);    //{3,2,1}
    // st.push(4);    //{4,3,2,1}
    // st.push(5);    //{5,4,3,2,1}
    // st.emplace(6); //{6,5,4,3,2,1}

    // st.pop(); //{5,4,3,2,1}
    // cout << st.top() << " ";

    // st.pop(); //{4,3,2,1}

    // cout<< st.empty();
    // cout << st.size() << " ";

    // queue
    // fifo
    // queue<int> q;
    // q.push(1);    // {1}
    // q.push(2);    // {1,2}
    // q.emplace(4); // {1,2,4}

    // q.back() += 5;
    // // Queue is {1,2,9}
    // cout << q.back();  // prints 9
    // cout << q.front(); // prints 1

    // q.pop(); //{2,9}

    // cout << q.front(); //prints 2

    // Priority Queue
    // Max element stays at the top
    // priority_queue<int> pq; // Max Heap

    // pq.push(2);     //{2}
    // pq.push(5);     //{3,2}
    // pq.push(3);     //{5,3,2}
    // pq.push(8);     //{8,5,3,2}
    // pq.emplace(10); //{10,8,5,3,2}

    // cout << pq.top()<< " ";

    // pq.pop(); //{8,5,3,2}

    // cout << pq.top()<< " ";

    // Minheap
    // priority_queue<int, vector<int>, greater<int>> pq;
    // pq.push(2);     //{2}
    // pq.push(5);     //{2,3}
    // pq.push(3);     //{2,3,5}
    // pq.push(8);     //{2,3,5,8}
    // pq.emplace(10); //{2,3,5,8,10}

    // cout << pq.top() << " ";

    // SET Container

    // Stores everything in sorted order and unique
    // set<int> st;

    // st.insert(1);
    // st.insert(2);
    // st.emplace(2);
    // st.insert(3);
    // st.insert(3);
    // st.insert(4);
    // st.insert(5);
    // st.insert(4);

    // auto it1 = st.find(2);
    // auto it2 = st.find(4);

    // st.erase(it1,it2); // erase between specified iterator

    // for (auto it : st)
    // {
    //     cout << it << " ";
    // }


    //MULTISET STORES MULTIPLE OCCURRENCE IN SORTED MANNER
    return 0;
}