#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2E5 + 10;
int n, m, k, t;
int languge[3 * N], a[N], b[N], c[N], cnt[3 * N];

void discrete() {
    sort(languge + 1, languge + 1 + t);
    k = unique(languge + 1, languge + 1 + t) - languge;
}

int query(int x) {
    return lower_bound(languge + 1, languge + 1 + k, x) - languge;
}

signed main() {
    cin >> n;
    // 读入科学家会的语言
    for(int i = 1; i <= n; i ++ ) cin >> a[i], languge[++ t] = a[i];
    cin >> m;
    // 读入听的语言
    for(int i = 1; i <= m; i ++ ) cin >> b[i], languge[++ t] = b[i];
    // 读入看的语言
    for(int i = 1; i <= m; i ++ ) cin >> c[i], languge[++ t] = c[i];
    // 离散化所有语言
    discrete();
    // 统计科学家会的语言数量
    for(int i = 1; i <= n; i ++ )
        cnt[query(a[i])] ++;
    // 遍历每场电影，找出最优解
    int idx = 1, max_num = 0, max_see_num = 0;
    for(int i = 1; i <= m; i ++ ) {
        int x = cnt[query(b[i])]; // 能听懂第i场电影的科学家人数
        int y = cnt[query(c[i])]; // 能看懂第i场电影的科学家人数
        if(x > max_num || (x == max_num && y > max_see_num)) {
            idx = i;
            max_num = x;
            max_see_num = y;
        }
    }
    cout << idx << "\n";
}