#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> p; // by default Max heap

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    cout<<p.top()<<endl;

    //delete
    p.pop();
    cout<<p.top()<<" ";

    //size
    p.size();

    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;

    //Min heap
    // priority_queue<int, vector<int>, greater<int> >p; // rest all functions are similar

    return 0;
}