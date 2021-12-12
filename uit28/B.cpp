#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, a[N];
long long sum[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sum[n+1] = ans[n+1] = 0;
    for(int i=n; i; --i) sum[i] = sum[i+1] + a[i];
    for(int i=n; i; --i) {
        if (i>=n-2) {
            ans[i] = sum[i];
            continue;
        }
        ans[i] = 0;
        ans[i] = max(ans[i], (sum[i] - sum[i + 1]) + (sum[i + 1] - ans[i + 1]));
        ans[i] = max(ans[i], (sum[i] - sum[i + 2]) + (sum[i + 2] - ans[i + 2]));
        ans[i] = max(ans[i], (sum[i] - sum[i + 3]) + (sum[i + 3] - ans[i + 3]));
    }
    cout << ans[1] << '\n';
}
