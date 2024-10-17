#include <bits/stdc++.h>
using namespace std;

float fact(int n){
    int fact = 1;
    for(int i=1 ; i<=n ; i++) fact = fact*i;
    return fact;
}

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    int mistakes[n];
    int pages[n];
    cout<<"Enter the number of mistakes(per page) : ";
    for(int i=0; i<n; i++){
        cin>>mistakes[i];
    }
    cout<<"Enter the number of pages : ";
    for(int i=0; i<n; i++){
        cin>>pages[i];
    }
    float sumOfmistakes = 0, sumOfpages = 0;
    for(int i=0; i<n; i++){
        sumOfmistakes += mistakes[i]*pages[i] ;
        sumOfpages += pages[i] ;
    }
    float lambda = sumOfmistakes/sumOfpages;

    float pmf[n],exp_freq[n];
    for(int i=0; i<n; i++){
        pmf[i] = (exp(-lambda)*pow((lambda),(mistakes[i])))/fact(mistakes[i]);
        exp_freq[i] = sumOfpages*pmf[i];
        cout<<"Expected frequency for "<<mistakes[i]<<" mistakes per page is : "<<exp_freq[i]<<endl;
    }

    float F[n];
    F[0] = exp_freq[0];
    cout<<"F(0) = "<<F[0]<<endl;
    for(int i=1; i<=n; i++){
        F[i] = (lambda*F[i-1])/(mistakes[i-1]+1);
        cout<<"F("<<i<<") = "<<F[i]<<endl;
    }
}
