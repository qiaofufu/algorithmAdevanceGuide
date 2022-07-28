#include <algorithm>
using namespace std;

const int N = 1E5+10;
int m = 0;
int b[N];

void discrete(int a[], int n) { // 离散化
    sort(a + 1, a + 1 + n);
    // 下面可用stl中的unique函数代替
    for(int i = 1; i <= n; i ++) {
        if(i == 1 || a[i] != a[i - 1])
            b[++m] = a[i];
    }
}

int query(int x) { // 查询x映射到1~m中哪个数字
    return lower_bound(b + 1, b + 1 + m, x) - b;
}