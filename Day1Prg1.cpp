
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {38,40,47,44,46,43,49,53};
    int m = 0;
    cout<<"Mean is : ";
    for(int i=0; i<8; i++){
        m = arr[i] + m;
    }
    int mean = m/8;
    cout<<(mean);

    cout<<"\nVariance is : ";
    float v = 0;
    for(int j=0; j<8; j++){
        v = (mean-arr[j])*(mean-arr[j]) + v;
    }
    float var = v/8;
    cout<<var;

    cout<<"\nCoefficient of Variation is : "<<(var/mean);
}
