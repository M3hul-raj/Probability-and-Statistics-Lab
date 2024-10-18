#include <bits/stdc++.h>
using namespace std;

void confidence_interval(float a[], int n, float perc){

    float sum = 0;
    for(int i=0; i<n ; i++){
        sum += a[i];
    }
    float mean = sum/n;
    float diff = 0;
    for(int j=0; j<n; j++){
        diff += pow(a[j] - mean,2);
    }
    float variance = diff/n;
    float SD = sqrt(variance);

    cout<<"Two-sided 95% confidence interval for the variance is : ["<<((n-1)*variance)/32.852<<", "<<((n-1)*variance)/8.907<<"]"<<endl;
    cout<<"Two-sided 95% confidence interval for the standard deviation is : ["<<((n-1)*SD)/32.852<<", "<<((n-1)*SD)/8.907<<"]"<<endl<<endl;
}

int main(){
    float dia[] = {2.02, 1.94, 2.09, 1.95, 1.98, 2.00, 2.03, 2.04, 2.08, 2.07, 1.99, 1.96, 1.99, 1.95, 1.99, 1.99, 2.03, 2.05, 2.01, 2.03};
    int n1 = sizeof(dia)/sizeof(dia[0]);
    confidence_interval(dia,n1,95);

    float furniture[] = {581, 580, 581, 577, 580, 581, 577, 579, 579, 578, 581, 583, 577, 578, 582, 581, 582, 580, 582, 579};
    int n2 = sizeof(furniture)/sizeof(furniture[0]);
    confidence_interval(furniture,n2,95);
}
