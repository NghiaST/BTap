#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int n, x, cnt, res;
string s;

void Enter() {
    cin >> n >> s;
}

void Process() {
    if (n % 3 != 0) return (void) (cout << "NO");
    int cnt_s = n / 3 * 2, cnt_o = n / 3;
    for(int i=0; i<n; ++i) {
        if (s[i] == 'O') --cnt, --cnt_o;
        else ++cnt, --cnt_s;
        if (cnt < 0 || cnt_s < cnt_o || cnt_s < 0 || cnt_o < 0) return (void) (cout << "NO");
    }
    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
