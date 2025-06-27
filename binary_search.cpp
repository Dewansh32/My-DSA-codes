#include<iostream>
using namespace std;

int binary_search(int arr[],int ele,int l,int r) // The array should be sorted to apply binary search
{
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == ele) return mid;
        else if(arr[mid]>ele) r = mid-1;
        else l = mid+1;
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

    int l=0;
    int r=n-1;

    int res = binary_search(arr,ele,l,r);
    if(res == -1)
    {
        cout<<"The element entered is not present in array"<<endl;
    }
    else
    {
        cout<<"The element you searched is present at: "<<res+1<<"th position in array"<<endl;
    }

    return 0;
}