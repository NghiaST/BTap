#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
struct point {long long x,y;};
point a[100005],b[100005];
long long n,w,cnt;
long double res;

int check(point p1,point p2,point p3) {
    long long e1,e2,q1,q2,t;
    e1=p2.x-p1.x;
    e2=p3.x-p2.x;
    q1=p2.y-p1.y;
    q2=p3.y-p2.y;
    t=e1*q2-e2*q1;
    if (t>0) return 1;
    if (t<0) return -1;
    if (t==0) return 0;
}

bool cmp(point p1,point p2) {
    int c=check(a[1],p1,p2);
    if (c==1) return true;
    if (c==0 && (p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y))) return true;
    return false;
}

void tinh(point e1,point e2,point e3) {
    res+=abs((e2.x-e1.x)*(e3.y-e2.y)-(e3.x-e2.x)*(e2.y-e1.y));
}

void tinhdientich() {
    for(int i=3;i<=cnt;i++) tinh(b[1],b[i-1],b[i]);
    cout<<setprecision(1)<<fixed<<res/2<<"\n";
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    w=1;
    for (int i=2;i<=n;i++) if (a[i].y<a[w].y || (a[i].y==a[w].y && a[i].x<a[w].x)) w=i;
    swap(a[w],a[1]);
    if (n>2) sort(a+2,a+n+1,cmp);
    cnt=1;b[1]=a[1];
    for(int i=2;i<=n;i++) if (a[i].x!=a[i-1].x || a[i].y!=a[i-1].y) {
        while (cnt>1 && check(b[cnt-1],b[cnt],a[i])<=0) cnt--;
        b[++cnt]=a[i];
       }
    while (cnt>2 && check(b[cnt-1],b[cnt],a[1])<=0) cnt--;
    cout<<cnt<<"\n";
    tinhdientich();
    for(int i=1;i<=cnt;i++) cout<<b[i].x<<" "<<b[i].y<<"\n";
}
