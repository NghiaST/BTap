#include <iostream>
using namespace std;
long long a,x,b;
int main()
{
    cin>>a>>x;b=a;
    if (a==0 && x==1) {cout<<0;return 0;}
    for(int i=0;i<x;i++) {
        a=a/10+((a%10)!=0);
    }
    a=max(a,min(1ll,x));
    while (x--) a*=10;
    cout<<a-b;
}
