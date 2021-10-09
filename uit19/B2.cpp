#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int n, m, k, a[N], c[N];
string M[1005];
int x;
string s, b[N];

void Enter() {
    cin >> n >> m >> k;
    FOR(i,1,k) cin >> x >> s, M[x] = s;
}

void Process() {
    FOR(i,1,n) {
        cin >> b[i] >> x >> s;
        REP(j,0,m) if (M[x][j] == s[j]) ++a[i];
    }
    for(int i=1; i<=n; ++i) c[i] = i;
    sort(c+1, c+n+1, [] (int x, int y) { return a[x] > a[y]; });
    for(int i=1; i<=n; ++i) cout << b[c[i]] << ' ' << a[c[i]] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
