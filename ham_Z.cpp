#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,res,f[100005],z[100005],x[100005],L,R;
string s,k,q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);
    cin>>q; m1 = q.length();
    cin>>k; m2 = k.length();
    s=q+'@'+k; n=m1+m2+1;

    for(int i=m1+2;i<n;i++) {
        if (i<=R) z[i]=min(z[i-L],R-L+1);
        while (z[i]+i<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if (i>R) {L=i;R=z[i]+L-1;}
        x[i-m1-1]=z[i];
    }

    for(int i=0;i<m2;i++) if (i+x[i]==m2) {
        cout<<n-2-i;
        return 0;
    }
    cout<<n-1;
}
