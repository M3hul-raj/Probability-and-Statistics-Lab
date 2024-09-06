#include <bits/stdc++.h>
using namespace std;

float fact(int n)
{
    int fact = 1;
    for(int i=1 ; i<=n ; i++) fact = fact*i;
    return fact;
}

float binoCoeff(int n,int xi)
{
    float nCr = fact(n)/(fact(n-xi)*fact(xi));
    return nCr;
}

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int head[n];
    int freq[n];
    cout<<"Enter the value of x : ";
    for(int i=0; i<n; i++){
        cin>>head[i];
    }
    cout<<"Enter the value of f : ";
    for(int i=0; i<n; i++){
        cin>>freq[i];
    }
    float sumOfhead = 0, sumOffreq = 0;
    for(int i=0; i<n; i++){
        sumOfhead += head[i]*freq[i] ;
        sumOffreq += freq[i] ;
    }
    float mean = sumOfhead/sumOffreq;
    float prob = mean/n;

    float p[n],exp_freq[n];
    for(int i=0; i<n; i++){
        p[i] = binoCoeff(n,head[i])*pow(prob,head[i])*pow((1-prob),(n-head[i]));
        exp_freq[i] = sumOffreq*p[i];
        cout<<"Expected frequency for Number_of_Heads = "<<head[i]<<" is : "<<exp_freq[i]<<endl;
    }

    float F[n];
    F[0] = exp_freq[0];
    cout<<"F(0) = "<<F[0]<<endl;
    for(int i=1; i<=n; i++){
        F[i] = ((n-head[i])*prob*F[i-1])/((head[i]+1)*(1-prob));
        cout<<"F("<<i<<") = "<<F[i]<<endl;
    }
}
