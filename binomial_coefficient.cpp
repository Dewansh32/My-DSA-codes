#include<iostream>
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

int binomial_coefficient(int n,int r)
{
    int n_fact = factorial(n);
    int r_fact = factorial(r);
    int n_r_fact = factorial(n-r);

    int bc = n_fact/(r_fact*n_r_fact);
    return bc;
}

int main()
{
    int n,r;

    cout<< "Enter n for binomial_coefficent: ";
    cin>>n;
    cout<< "Enter r for binomial_coefficent but remember r < n : ";
    cin>>r;

    int bc = binomial_coefficient(n,r);
    cout<<"binomial_coefficient is: "<<bc;
    
    return 0;
}