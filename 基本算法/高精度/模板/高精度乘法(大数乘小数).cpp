#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

// a->大数 b->小数
vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || t; i ++ ) {
        if(i < a.size())t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    vector<int> a = {0,0,0,0,1};
    int b = 0;
    auto f = mul(a, b);
    reverse(f.begin(), f.end());
    for(auto i : f) {
        cout << i;
    }
}
