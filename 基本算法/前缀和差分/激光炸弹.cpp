#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E3+50;

int a[MAXN][MAXN];
int x, y, w, r, n, u, v;

void solve() {
    for(int i = 1; i <= u; i ++ )
        for(int j = 1; j <= v; j ++ )
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    int ans = 0;
    for(int i = r; i <= u; i ++ )
        for(int j = r; j <= v; j ++ )
            ans = max(ans, a[i][j] - a[i - r][j] - a[i][j - r] + a[i-r][j-r]);
    cout << ans << "\n";
}

int main() {
    cin >> n >> r;
    r = min(r, 5001);
    u = v = r;
    for(int i = 1; i <= n; i ++ ) {
        cin >> x >> y >> w;
        x++;
        y++;
        a[x][y] += w;
        u = max(u, x);
        v = max(v, y);
    }
   
    solve();
}