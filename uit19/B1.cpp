#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 205;
int n, m, k, a[N];
long long f[N][N];

void Enter() {
}

void Process() {
    cin >> n >> k;
    f[0][0] = 1;
    for(int i=1; i<=n; ++i) {
        f[i][0] = 1;
        for(int j=1; j<=i; ++j) f[i][j] = f[i-1][j] + f[i-1][j-1];
    }
    if (k > n) cout << -1;
    else cout << f[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
