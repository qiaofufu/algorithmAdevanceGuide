#include <bits/stdc++.h>

using namespace std;

const int N = 1E5+10;
const int INF = 1E9;

int n, d, x, y;
bool flag = false;
pair<double, double> pos[N];

void solve() {
    if(flag) {
        cout << "-1\n";
        return;
    }
    sort(pos + 1, pos + 1 + n, [](auto a, auto b){return a.second < b.second;});
    double now = -INF;
    int ans = 0;
    for(int i = 1; i <= n; i ++ )
        if(now < pos[i].first) {
            ans ++;
            now = pos[i].second;
        } else {
            now = min(pos[i].second, now);
        }
    cout << ans << "\n";
}

signed main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++ ) {
        cin >> x >> y; 
        if(y > d) flag = true;
        pos[i].first = x - sqrt(d * d - y * y);
        pos[i].second = x + sqrt(d * d - y * y);
    }
    solve();
}