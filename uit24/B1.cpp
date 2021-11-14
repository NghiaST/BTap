#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;
const int N = 500005;
int n, m, r, res, a[N];
long long f[N], Q[N];

void DQ(int x, long long val) {
    if (x == 0) {
        Q[r++] = val;
        return;
    }
    DQ(x-1, val);
    DQ(x-1, val + f[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    f[0] = 1;
    for(int i=1; i<=17; ++i) f[i] = f[i-1] * 5;
    DQ(17, 0);
    cin >> n;
    cout << Q[n];
}
