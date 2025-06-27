#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n==1)
    {
        return 1;
    }

    int fact = 1;

    for(int i = 1;i<=n;i++)
    {
        fact = fact * i;
    }

    return fact;
}

int main()
{
    int n;
    cout<<"enter number to take out factorial";
    cin>>n;

    int fact = factorial(n);
    cout<<"Factorial of "<<n<<" is: "<<fact;

    return 0;
}