#include <bits/stdc++.h>
using namespace std;
long long n, x, y, f[85];
string s, s2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s >> s2;
    f[0] = s.length(); f[1] = s2.length();
    for(int i=2; i<=80; ++i) f[i] = f[i-2] + f[i-1];
    cin >> n;
    while (n--) {
        cin >> x >> y;
        --x;
        while (x > 1) {
            if (y <= f[x - 2]) x -= 2;
            else y -= f[x-2], --x;
        }
        if (x==0) cout << s[y-1];
        else cout << s2[y-1];
    }
}
