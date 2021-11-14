#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;
const int N = 500005;
int n, m, r, res, a[N];
int Q[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >>n;
    while (n--) cin >> m, ++Q[m];
    cout << Q[1] << ' ' << Q[12] << ' ' << Q[0] << ' ' << Q[6];
}
