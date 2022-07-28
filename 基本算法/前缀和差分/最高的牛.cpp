#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E3+10;
int n, p, h, m, a, b, c[MAXN];
set<pair<int, int>> existed;
int main() {
    cin >> n >> p >> h >> m;
    for(int i = 1 ; i <= m; i ++ ) {
        cin >> a >> b;
        if(b < a) swap(a, b);
        if(existed.find({a, b}) != existed.end()) continue;
        existed.insert({a, b});
        c[a+1] --;
        c[b]++;
    }

    for(int i = 1; i <= n; i ++ )
        c[i] += c[i-1];
    for(int i = 1; i <= n; i ++ )
        cout << c[i] + h << "\n";
}