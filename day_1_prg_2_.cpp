/* The total marks scored by two students A and B in 5 subjects are 460 and 480 with standard deviation 4.6 and 2.4 respectively.
   Who is more consistent in performance? */

#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter total marks by both students : ";
    cin>>a>>b;

    float m1,m2;
    m1 = a/5;
    m2 = b/5;

    float x,y;
    cout<<"Enter standard deviation of both students : ";
    cin>>x>>y;

    if(x/m1 > y/m2) cout<<"B is more consistent in performance.";
    else cout<<"A is more consistent in performance.";
}
