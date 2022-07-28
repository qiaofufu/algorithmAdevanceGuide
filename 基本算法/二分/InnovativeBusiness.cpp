#include <bits/stdc++.h>
using namespace std;
extern bool compare(int a, int b); // compare() API

// 以下为提交代码
class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 2; i <= N; i ++ ) {
            int l = 0, r = ans.size();
            while(l < r) {
                int mid = (l + r) >> 1;
                if(compare(i, ans[mid])) { // compare() O(NlongN)
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans.insert(ans.begin() + l, i); // O(n^2)
        }
        return ans;
    }
};