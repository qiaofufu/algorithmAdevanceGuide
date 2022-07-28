#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

int n, a[N];

void solve() {
    int ans = 0, coordinate = 0;
    sort(a + 1, a + 1 + n);
    if(n % 2) {
        coordinate = a[(n + 1) / 2];
    } else {
        coordinate = a[n / 2];
    }
    for(int i = 1; i <= n; i ++ )
        ans += abs(coordinate - a[i]);
    cout << ans << "\n";
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    solve();
}