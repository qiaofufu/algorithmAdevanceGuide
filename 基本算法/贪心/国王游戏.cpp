#include <bits/stdc++.h>

using namespace std;

const int N = 1E3+10;
int n;
pair<int, int> a[N];

vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    for(int i = 0, t = 0; i < a.size() || t; i ++ ) {
        if(i < a.size())t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

vector<int> div(vector<int> a, int b) {
    vector<int> c;
    int r = 0;
    for(int i = a.size() - 1; i >= 0; i -- ) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

vector<int> max(vector<int> a, vector<int> b) {
    if(a.size() > b.size()) return a;
    else if(a.size() < b.size()) return b;
    else {
        for(int i = a.size() - 1; i >= 0; i --)
            if(a[i] > b[i]) return a;
            else if(a[i] < b[i]) return b;
    }
    return a;
}

void solve() {
    sort(a + 1, a + 1 + n, [](auto a, auto b){return a.first*a.second < b.first*b.second;});
    vector<int> ans, base;
    for(int i = a[0].first; i; i /= 10) base.push_back(i % 10);
    for(int i = 1; i <= n; i ++ )
        ans = max(ans, div(base, a[i].second)), base = mul(base, a[i].first);
    reverse(ans.begin(), ans.end());
    for(auto i: ans) 
        cout << i;
    cout << "\n";
}

signed main() {
    cin >> n;
    for(int i = 0; i <= n; i ++ ) cin >> a[i].first >> a[i].second;
    solve();
}