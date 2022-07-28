#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+10;
const int M = 100;

int dp[N][M], a[N] = {0,3,5,9,11,4,2}, n = 6;

void create_ST() {
    for(int i = 1; i <= n; i ++ ) dp[i][0] = a[i];
    int t = log2(n) + 1;
    for(int j = 1; j < t; j ++ )
        for(int i = 1; i <= n - (1 << j) + 1; i ++ ) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j-1))][j - 1]);
        }
}

int query_ST(int l, int r) {
    int k = log2(r - l + 1);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}

int main() {
    create_ST();
    int l, r;
    while(cin >> l >> r) {
        cout << query_ST(l, r) << "\n";
    }
}