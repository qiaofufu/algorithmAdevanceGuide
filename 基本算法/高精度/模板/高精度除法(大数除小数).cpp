#include <bits/stdc++.h>

using namespace std;

const int N = 1E5 + 10;

vector<int> div(vector<int> a, int b, int &r) {
    vector<int> c;
    r = 0;
    for(int i = a.size() - 1; i >= 0; i -- ) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main() {
    vector<int> a = {1,3,9,8,4,6,3};
    int b = 21, r = 0;
    auto f = div(a, b, r);
    reverse(f.begin(), f.end());
    for(auto i: f) {
        cout << i;
    }
    cout << " " << r << "\n";
}