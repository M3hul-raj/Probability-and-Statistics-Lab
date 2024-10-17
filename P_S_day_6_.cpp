#include <bits/stdc++.h>
using namespace std;

void Pearsons_Corr_coeff(float x[],float y[],int n){
    float sumx = 0 , sumy = 0;
    for(int i=0; i<n; i++){
        sumx += x[i];
        sumy += y[i];
    }
    float mean_x = sumx/n;
    float mean_y = sumy/n;
    float a = 0, b = 0, c = 0;
    for(int i=0; i<n; i++){
        a += (x[i] - mean_x)*(y[i] - mean_y);
        b += (x[i] - mean_x)*(x[i] - mean_x);
        c += (y[i] - mean_y)*(y[i] - mean_y);
    }
    cout<<"Pearson's Correlation coefficient is : "<<a/sqrt(b*c)<<endl;
}

float* Rank(float arr[], int n){
    float* dup = new float[n];
    for(int k=0; k<n; k++){
        dup[k] = arr[k];
    }

    int temp = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    float rank[n];
    for(int r=0; r<n; r++){
        if(arr[r]!=arr[r+1]){
            rank[r] = r+1;
        }
        else{
            rank[r] = ((r+1)+(r+2))/2.0;
            rank[r+1] = rank[r];
            r = r+1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]==dup[j]) dup[j] = rank[i];
        }
    }
    return dup;
}

void Spearmans_rank_corr_coeff(float x[],float y[],int n){
    float* rank_x = Rank(x,n);
    float* rank_y = Rank(y,n);
    
    float sum_d = 0;
    for(int i=0; i<n; i++){
        sum_d += pow(rank_x[i] - rank_y[i],2);
    }
    float spearmans_rank = (1 - (6*sum_d)/(n*n*n-n));
    cout<<"Spearman's rank correlation coefficient is : "<<spearmans_rank;
}

int main()
{
    float x[] = {10, 8, 12, 15, 8, 10};
    float y[] = {7, 4, 6, 7, 9, 8};
    int n = sizeof(x)/sizeof(x[0]);
    Pearsons_Corr_coeff(x,y,n);
    Spearmans_rank_corr_coeff(x,y,n);
}