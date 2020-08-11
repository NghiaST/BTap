#include <bits/stdc++.h>
using namespace std;

int dem,res,c[1000005],head[1000005],link[2000005],y[2000005],n,m,u,v;

void visit(int u) {
    c[u]=true;
    int i=head[u],v;
    while (i) {
        v=y[i];
        if (!c[v]) visit(v);
        i=link[i];
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>u>>v;
        link[i]=head[u];head[u]=i;y[i]=v;
        link[i+m]=head[v];head[v]=i+m;y[i+m]=u;
    }
    for(int i=1;i<=n;i++) if (!c[i]) {
        dem++;
        visit(i);
    }
    if (dem!=1) cout<<"+"<<dem-1;
    else cout<<"-"<<m-n+1;
}
