#include <bits/stdc++.h>
using namespace std;

const int N = 2510;

pair<int,int> cattle[N], spf[N];
int c, l;

void solve() {
    int ans = 0;
    sort(cattle + 1, cattle + c, [](auto x, auto y){return x.first >= y.first;});
    // sort(spf + 1, spf + l, [](auto x, auto y) {return x.first >= y.first;});
    for(int i = 1; i <= c; i ++ )
        for(int j = 1; j <= l; j ++ )
            if(spf[j].first >= cattle[i].first && spf[j].first <= cattle[i].second && spf[j].second ) {
                ans ++, spf[j].second --;
                break;
            }
    cout << ans << "\n";
}

signed main() {
    cin >> c >> l;
    for(int i = 1; i <= c; i ++ ) cin >> cattle[i].first >> cattle[i].second;
    for(int i = 1; i <= l; i ++ ) cin >> spf[i].first >> spf[i].second;
    solve();
}