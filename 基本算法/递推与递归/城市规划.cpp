#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, a, b;

pair<int, int> calc(int n, int m) {
    if(n == 0) return {0, 0};
    int cnt = 1ll << (2 * n - 2); // n级城市有多少个房子
    int len = 1ll << (n - 1); 
    auto pos = calc(n - 1, m % cnt);
    int x = pos.first, y = pos.second;
    int z = m / cnt; // idx号房子在哪个块中
    if(z == 0) return {y, x};
    if(z == 1) return {x, y + len};
    if(z == 2) return {x + len, y + len};
    if(z == 3) return {2 * len - y - 1, len - x - 1};
}


signed main() {
    cin >> t;
    while(t --) {
        cin >> n >> a >>  b;
        auto ac = calc(n, a - 1);
        auto bc = calc(n, b - 1);
        double dx = ac.first - bc.first, dy = ac.second - bc.second;
        printf("%0.lf\n", sqrt(dx * dx + dy * dy) * 10);
    }
}