/* By the method of least squares find the straight line to the data given below:
x    5   10   15   20   25
y   16   19   23   26   30  */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the total number of coordinates :";
    cin>>n;
    int arr[n];
    int brr[n];

    cout<<"Enter the elements in x :";
    for(int i=0; i<n; i++) cin>>arr[i];
    
    cout<<"Enter the elements in y :";
    for(int j=0; j<n; j++) cin>>brr[j];
    
    int sumx = 0, sumy= 0 ,sumxy = 0 , sumx2 = 0;
    for(int i=0; i<n; i++){
        sumx = arr[i] + sumx;
        sumy = brr[i] + sumy;
        sumxy = arr[i]*brr[i] + sumxy;
        sumx2 = arr[i]*arr[i] + sumx2;
    }
    float m = (float)(n*sumxy - sumx*sumy)/(n*sumx2 - (sumx*sumx));
    float c = (float)(sumy - m*sumx)/n;
    cout<<"The Equation of the best fit line is : ";
    cout<<"y = "<<m<<"x + "<<c;
}
