#include<iostream>
using namespace std;

int main()
{
    int a[5] = {6,2,1,5,3};
    int *q;

    q=a;
    cout<<a<<endl;
    cout<<q<<endl;
    q++;
    cout<<q<<endl;
    cout<<a[2]<<endl;
    cout<<*(a+2)<<endl;
    cout<<*(q+1)<<endl;
    cout<<a+1<<endl;
    cout<<&a+1<<endl;
    cout<<*(a+1)<<endl;
    cout<<*a+1<<endl;

}