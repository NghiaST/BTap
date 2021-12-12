#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
long long t, n, res, a[N], f[N];

void Enter() {
    cin >> n;
}

void Process() {
    res = 1;
    while (n) {
        res = max(res, n % 10);
        n /= 10;
    }
    cout << "Tong " << res << " so nhi phan. ";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}
