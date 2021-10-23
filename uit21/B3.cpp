#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 1005;
int n, m, k, res, f[N][N], b[N];
pair<int,int> a[N];
string s;

void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
}

void Process() {
    for(int i=1; i<=n; ++i) b[i] = a[i].first;

    for(int i=1; i<=n; ++i) {
        f[i][i] = a[i].second;
        res = max(res, f[i][i]);
        for(int j=i-1; j>=0; --j) {
            int p = lower_bound(b, b+j, b[j] - (b[i] - b[j])) - b;
            f[i][j] = max(f[i][j+1], f[j][p] + a[i].second);
            res = max(res, f[i][j]);
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
