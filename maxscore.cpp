#include <iostream>
using namespace std;
long long n,res,sum,x,oo=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        res=(res+x*sum)%oo;
        sum=(sum+x)%oo;
    }
    cout<<res;
}
