#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

// a > b and a>0 and b>0;
vector<int> sub(vector<int> a, vector<int> b) {
    vector<int> c;
    for(int i = 0, t = 0; i < a.size(); i ++) {
        t += a[i];
        if(i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        if(t < 0) t = -1;
        else t = 0;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    vector<int> a = {0,0,1}, b = {9, 9};
    auto f = sub(a, b);
    reverse(f.begin(), f.end());
    for(auto i : f) {
        cout << i;
    }
}