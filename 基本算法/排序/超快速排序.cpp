#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5E5+10;
int n, a[N], b[N], cnt;

void merge(int l, int r) {
    // cout << "l " << l << " r " << r << "\n";
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k ++ ) {
        if(j > r || i <= mid && a[i] <= a[j]) 
            b[k] = a[i ++];
        else 
            b[k] = a[j ++], cnt += mid - i + 1;
    }
    for(int k = l; k <= r; k ++) 
        a[k] = b[k];
}

void solve() {
    cnt = 0;
    merge(1, n);
    cout << cnt << "\n";
}

signed main() {
    while(cin >> n && n) {
        for(int i = 1; i <= n; i ++ )
            cin >> a[i];
            solve();
    }
    
}