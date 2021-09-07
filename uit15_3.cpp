#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int MOD = 1e7 + 9;
const int N = 100005;
int n, r, ans[3005], f[4], f2[4];
pair<int,int> Q[3005];
string s;

void Enter() {
    while (cin >> n, n > 0) ++r, Q[r] = {n, r};
    sort(Q+1, Q+r+1);
    f[0] = f[1] = f[2] = f[3] = 1;
    for(int i=3, j=1; i<=10000000; ++i) {
        for(int j=0; j<4; ++j) f2[j] = f[j];
        f[0] = f2[2];
        f[1] = (f2[0] + f2[2]) % MOD;
        f[2] = f2[3];
        f[3] = (f2[1] + f2[3]) % MOD;
        while (j <= r && Q[j].first == i) ans[Q[j].second] = (f[0] + f[1] + f[2] + f[3]) % MOD, ++j;
        if (j > r) break;
    }
    for(int i=1; i<=r; ++i) cout << ans[i] << ' ';
}

int main()
{
    Enter();
}
