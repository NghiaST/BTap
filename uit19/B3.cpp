#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 1005;
int n, m, k, a[N];
long long f[N][N], res;

void Enter() {
    cin >> n;
    FOR(i,1,n) cin >> a[i];
}

void Process() {
    for(int i=2; i<=n; ++i)
    for(int j=i-2; j; --j) {
        for(int w=j+1; w<i; ++w) f[j][i] = max(f[j][i], f[j][w] + f[w][i]);
        f[j][i] += a[i] * a[j];
    }
    cout << f[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
