#include<iostream>
using namespace std;

int linear_search(int arr[],int n,int ele)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int ele;
    cout<<"Enter element to search: ";
    cin>>ele;
    int x=linear_search(arr,n,ele);
    if(x==-1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element you asked for is at "<<x+1<<"th place";
    }
    
    return 0;
}