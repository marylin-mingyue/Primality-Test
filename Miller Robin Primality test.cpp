#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

// 快速幂
ll Q_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bool MillerRabin(ll n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;

    vector<ll> base = {2, 325, 9375, 28178, 40775, 9780504, 1795265022};
    ll s = 0;
    ll u = n - 1;

    while (u % 2 == 0) {
        u /= 2;
        s++;
    }

    for (auto a : base) {
        if (a % n == 0) continue;
        ll x = Q_pow(a, u, n);
        if (x == 1 || x == n - 1) continue;

        bool found = false;
        for (int r = 1; r < s; r++) {
            x = x * x % n;
            if (x == n - 1) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// 将字符串转换为 __int128
ll stringToInt128(const string& str) {
    ll result = 0;
    for (char c : str) {
        result = result * 10 + (c - '0');
    }
    return result;
}

int main() {
    string input;
    while (getline(cin, input)) {
        ll n = stringToInt128(input); // 使用自定义函数转换
        if (MillerRabin(n)) cout << "Y" << endl;
        else cout << "N" << endl;
    }
}