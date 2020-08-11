#include <bits/stdc++.h>
using namespace std;

long long t,n,x,oo=1e9,z[1000005],res,r;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>t;
    while (t--) {
        memset(z,0,sizeof(z));
        cin>>n;
        r=0;res=1;int dem=0,l;
        for(int i=1;i<=n;i++) {
            cin>>x;
            if (x==1) res=-1;r=max(r,x);
            for(int j=2;j*j<=x;j++) if (x%j==0) {
                long long g=0;
                while (x%j==0) x/=j,g++;
                z[j]=max(z[j],g);
            }
            if (x!=1) z[x]=max(z[x],1ll);
        }
        for(int i=2;i<=1000000;i++) if (z[i]) {res=min(n+4,res*z[i]+res);dem++;l=i;}
        if (dem==1) res++;
        if (n!=res-2) cout<<-1<<"\n";else {
            long long o=1;
            for(int i=1;i<=1000000;i++) if (z[i]) {
                int c=1;
                while (z[i]--) c*=i;
                o=o*c;
            }
            if (o==r && dem==1) o=o*l;
            if (o==r) cout<<-1<<"\n";else cout<<o<<"\n";
        }
    }
}
