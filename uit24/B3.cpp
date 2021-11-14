#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
using namespace std;
const int N = 500005;
int n, m, r, res, a[N];
char s[N], Q[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    n = strlen(s);
    for(int i=0; i<n; ++i) {
        if (r > 0 && Q[r] == s[i]) --r;
        else Q[++r] = s[i];
    }
    for(int i=1; i<=r; ++i) cout << Q[i];
}
