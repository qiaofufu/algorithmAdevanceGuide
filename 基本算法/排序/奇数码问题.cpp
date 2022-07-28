#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 510 * 510;

int n, t, a[N], b[N], c[N], k, cnt;

void merge(int l, int r, int a[]) {
   if(l >= r) return;
    int mid = l + (r - l) / 2;
    merge(l, mid, a);
    merge(mid + 1, r, a);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k ++ ) {
        if(j > r || i <= mid && a[i] <= a[j]) 
            c[k] = a[i ++];
        else 
            c[k] = a[j ++], cnt += mid - i + 1;
    }
    for(int k = l; k <= r; k ++) 
        a[k] = c[k];
}

void solve() {
    int a_c, b_c;
    cnt = 0;
    merge(0, n * n - 2, a);
    a_c = cnt;
    cnt = 0;
    merge(0, n * n - 2, b);
    b_c = cnt;
    if(a_c % 2 != b_c % 2) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n";
    }
}

void read(int a[]) {
    k = 0;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ ) {
            cin >> t;
            if(t) a[k ++] = t;
        }
}

signed main() {
    while(cin >>n && n) {
        read(a);
        read(b);
        solve();
    }
}