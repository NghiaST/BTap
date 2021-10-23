#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
long long f[100005], f2[100005], res;
vector<pair<int,int>> S[100005], S2[100005];

void DFS(int u, int pa) {
    for(pair<int,int> w : S[u]) if (w.first != pa) {
        int v = w.first, c = w.second;
        DFS(v, u);
        f[v] -= c;
        if (f2[u] < f[v]) f2[u] = f[v];
        if (f[u] < f2[u]) swap(f[u], f2[u]);
    }
    f[u] += a[u];
    res = max(res, f[u] + f2[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        S[u].emplace_back(v, c);
        S[v].emplace_back(u, c);
    }
    DFS(1, 0);
    cout << res;
}
