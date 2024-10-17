#include <iostream>
#include <math.h>
using namespace std;

void regression(float *x, float *y, int n){
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

    float mean_y = sumy/n;
    float mean_x = sumx/n;

    float sumation_x = 0;
    float sumation_y = 0;
    for(int i=0; i<n; i++){
        sumation_x += (x[i] - mean_x)*(x[i] - mean_x);
        sumation_y += (y[i] - mean_y)*(y[i] - mean_y);
    }
    float SDx = sqrt((sumation_x)/n);
    float SDy = sqrt((sumation_y)/n);

    cout<<"Regression line of y on x is : y = "<<(correlation*SDy/SDx)<<"x + ("<<((mean_y)-(correlation*SDy*mean_x/SDx))<<")"<<endl;
    cout<<"Regression line of x on y is : x = "<<(correlation*SDx/SDy)<<"y + ("<<((mean_x)-(correlation*SDx*mean_y/SDy))<<")"<<endl<<endl;
}

int main()
{
    float x2[] = {3,3,4,5,6,6,7,8,8,9};
    float y2[] = {9,5,12,9,14,16,22,18,24,22};
    int n2 = sizeof(x2)/sizeof(x2[0]);
    regression(x2,y2,n2);
    float x1[] = {12.5, 5.0, 3.0, 5.0, 6.5, 6.0, 4.0, 7.0, 5.5, 4.0};
    float y1[] = {10, 26, 41, 29, 27, 19, 18, 20, 28, 33};
    int n1 = sizeof(x1)/sizeof(x1[0]);
    regression(x1,y1,n1);
}
