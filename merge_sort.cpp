#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int st,int mid,int end)
{
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0;idx<temp.size();idx++)
    {
        arr[idx+st] = temp[idx];
    }    
}

void merge_sort(int arr[],int st,int end)
{
    if(st<end)
    {
        int mid = st + (end-st)/2;
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);

        merge(arr,st,mid,end);
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

    merge_sort(arr,0,n-1);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}