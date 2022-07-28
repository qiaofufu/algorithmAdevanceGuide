#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

int n, k, a[N];

int func(int l, int r, int k) {
    if(l == r)  return a[l];
    int i = l, j = r;
    int key = a[l];
    while(i < j) {
        while(i < j && a[j] >= key) j --;
        swap(a[i], a[j]);
        while(i < j && a[i] <= key) i ++;
        swap(a[i], a[j]);
    }

    int t = i - l + 1;
    if(k > t) return func(i + 1, r, k - t);
    else if(k < t) return func(l, i, k);
    else return a[i];
}


void solve() {
    cout << func(1, n, k) << "\n";
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    solve();
}