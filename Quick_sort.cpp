#include<iostream>
using namespace std;

int partition(int arr[],int st,int end)
{
    int idx = st-1;
    int pvt = arr[end];
    for(int j=st;j<=end-1;j++)
    {
        if(arr[j]<=pvt)
        {
            idx++;
            swap(arr[j],arr[idx]);
        }
    }

    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quick_sort(int arr[],int st,int end)
{
    if(st<end)
    {
        int pvt_idx = partition(arr,st,end);
        quick_sort(arr,st,pvt_idx-1);
        quick_sort(arr,pvt_idx+1,end);
    }
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

    quick_sort(arr,0,n-1);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}