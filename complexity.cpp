#include <iostream>
using namespace std;
long long l,r,k;

int main()
{
    cin>>l>>r>>k;
    cout<<(r*(r+1)*(r+2)-l*(l+1)*(l-1))/6;
}
