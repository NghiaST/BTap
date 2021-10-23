#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int n, m, k, res, a[N];
long long f[N];
string s;

void Enter() {
    cin >> s >> n;
    cin >> s;
}

void Process() {
    for(int i=0; i<n; ++i) {
        int j=i;
        while (j<n && s[i]==s[j]) ++j;
        res += (j - i) / 2;
        i = j - 1;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
