#include<iostream>
using namespace std;

int main()
{ 
    int arr[50] = {5,7,9,15,10,6};
    int sz = 6;

    int pos,item;
    cout<<"Enter pos you want to make free: ";
    cin>>pos;

    if(pos<=0 || pos>sz) cout<<"Invalid pos"<<endl;

    else
    {
        item = arr[pos-1];
        for(int i=pos-1;i<sz;i++)
        {
            arr[i] = arr[i+1];
        }
        sz--;
    }

    cout << "Array after insertion: ";
    for(int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}