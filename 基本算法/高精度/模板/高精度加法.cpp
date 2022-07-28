#include <bits/stdc++.h>

using namespace std;

// a, b -> 高位在右
vector<int> add(vector<int> a, vector<int> b) {
    if(a.size() < b.size()) return add(b, a);
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i ++ ) {
        t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) 
        c.push_back(t);
    return c;
}

int main() {
    vector<int> a = {1,8,5,9,4,9,8,1,7,6}, b = {1,8,5,9,4,9,8,1,7,6};
    auto c = add(a, b);
    reverse(c.begin(), c.end());
    for(auto i: c) {
        cout << i;
    }
}