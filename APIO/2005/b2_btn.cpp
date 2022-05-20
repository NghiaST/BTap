#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=(l); i<=(r); ++i)
#define REP(i, l, r) for(int i=(l); i<(r); ++i)
#define FORD(i, r, l) for(int i=(r); i>=(l); --i)
#define REPD(i, r, l)  for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 2e2 + 5;

const long long MOD = 1e18, ndigit = 18;
typedef vector<long long> BigNum;

void operator += (BigNum &A, BigNum B) {
    if (A.size() < B.size()) A.resize(B.size(), 0);
    long long carry = 0;
    REP(i, 0, A.size()) {
        carry += A[i];
        if (i < B.size()) carry += B[i];
        A[i] = carry % MOD;
        carry /= MOD;
    }
    if (carry) A.push_back(carry);
}

BigNum operator * (BigNum A, int B) {
    long long carry = 0;
    for(long long &v : A) {
        carry += v * B;
        v = carry % MOD;
        carry /= MOD;
    }
    if (carry) A.push_back(carry);
    return A;
}

ostream& operator << (ostream &os, BigNum A) {
    os << (A.empty() ? 0 : A.back());
    REPD(i, (int) A.size() - 1, 0) {
        int sz = (A[i] == 0);
        for(long long j = A[i]; j; j /= 10) ++sz;
        REP(j, sz, ndigit) os << 0;
        os << A[i];
    }
    return os;
}

int n, k;
BigNum dp[N][N], pow3[N];
char Q[N];
string s;

void Enter() {
    cin >> n >> k >> s;
}

void Process() {
    dp[0][0] = {1};
    FOR(i, 1, n) {
        FOR(j, 0, k) {
            if (j) dp[i][j] += dp[i - 1][j - 1];
            if (j < k) dp[i][j] += dp[i - 1][j + 1] * 3;
        }
    }
    pow3[0] = {1};
    FOR(i, 1, 100) pow3[i] = pow3[i - 1] * 3;

    int deg = 0;
    BigNum stt = {1};
    FOR(i, 1, n) {
        int deg_up = deg + 1, deg_dn = deg - 1;
        switch (s[i - 1]) {
            case '(' : {
                Q[++deg] = s[i - 1];
                break;
            }
            case ')' : {
                stt += dp[n - i][deg_up];
                --deg;
                break;
            }
            case '[' : {
                stt += dp[n - i][deg_up];
                if (Q[deg] == '(')
                    stt += dp[n - i][deg_dn];
                Q[++deg] = s[i - 1];
                break;
            }
            case ']' : {
                stt += dp[n - i][deg_up] * 2;
                --deg;
                break;
            }
            case '{' : {
                stt += dp[n - i][deg_up] * 2;
                if (Q[deg] == '(' || Q[deg] == '[')
                    stt += dp[n - i][deg_dn];
                Q[++deg] = s[i - 1];
                break;
            }
            case '}' : {
                stt += dp[n - i][deg_up] * 3;
                --deg;
                break;
            }
        }
    }
    cout << stt;
}

int main()
{
    #define file ""
    if (fopen(file".inp", "r")) {
        freopen(file".inp", "r", stdin);
        freopen(file".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
