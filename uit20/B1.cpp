#include <bits/stdc++.h>
using namespace std;
long long n, x, y, z;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> x >> y >> z;
        if (x <= 0 || y <= 0 || z < 0 || y > 12) cout << "FALSE";
        else if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) {
            cout << (x <= 31 ? "TRUE" : "FALSE");
        }
        else if (y == 4 || y == 6 || y == 9 || y == 11) {
            cout << (x <= 30 ? "TRUE" : "FALSE");
        }
        else if (z % 400 == 0 || z % 4 == 0 && z % 100 != 0) {
            cout << (x <= 29 ? "TRUE" : "FALSE");
        }
        else {
            cout << (x <= 28 ? "TRUE" : "FALSE");
        }
        if (n) cout << ' ';
    }
}
