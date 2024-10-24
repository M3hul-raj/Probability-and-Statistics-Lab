/* 1.  Draw a scatter plot for the given bivariate data and find the correlation coefficient between 𝑥 and 𝑦 for the data in the dosage example:
   Dosage (x)               | 3  3  4  5  6  6  7  8  8  9
   Duration of relief (y)   | 9  5  12 9  14 16 22 18 24 22  
   Draw a scatter plot for the given bivariate data.    

2. Soil temperature (x_i, in °C) and germination interval (y_i, in days) were observed for 
   winter wheat at 10 localities 
   x_i    | 12.5   5.0   3.0   5.0   6.5   6.0   4.0   7.0   5.5   4.0
   y_i    | 10     26    41    29    27    19    18    20    28    33 
   Draw a scatter plot for the given bivariate data. Find the correlation coefficient between x_i and y_i.   */

#include <iostream>
#include <math.h>
using namespace std;

void corr_coeff(float *x, float *y, int n){
    float sumxy = 0, sumx = 0, sumy = 0, sumx2 = 0, sumy2 = 0;
    for(int i=0; i<n; i++){
        sumxy += x[i]*y[i];
        sumx += x[i];
        sumy += y[i];
        sumx2 += x[i]*x[i];
        sumy2 += y[i]*y[i];
    }
    float Lxy = sumxy - (sumx*sumy)/n;
    float Lxx = sumx2 - (sumx*sumx)/n;
    float Lyy = sumy2 - (sumy*sumy)/n;
    float correlation = Lxy/sqrt(Lxx*Lyy);

    cout<<"Correlation coefficient between x and y is : "<<correlation<<endl<<endl;
}

int main()
{
    float x2[] = {3,3,4,5,6,6,7,8,8,9};
    float y2[] = {9,5,12,9,14,16,22,18,24,22};
    int n2 = sizeof(x2)/sizeof(x2[0]);
    corr_coeff(x2,y2,n2);
    float x1[] = {12.5, 5.0, 3.0, 5.0, 6.5, 6.0, 4.0, 7.0, 5.5, 4.0};
    float y1[] = {10, 26, 41, 29, 27, 19, 18, 20, 28, 33};
    int n1 = sizeof(x1)/sizeof(x1[0]);
    corr_coeff(x1,y1,n1);
}
