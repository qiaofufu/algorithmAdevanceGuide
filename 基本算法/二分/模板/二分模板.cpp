#include <bits/stdc++.h>

using namespace std;

// binarySearchA
// 找>=target 的第一个元素
int binarySearchA(int a[], int n, int target) {
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if(mid >= target) 
            r = mid;
        else 
            l = mid + 1;    
    }
    return a[l];  
} 

// binarySearchB
// 找<=target的最后一个元素
int binarySearchB(int a[], int n, int target) {
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r + 1) >> 1; // 防止 （l+r）>>1 == l 和 l = mid 造成死循环
        if(mid <= target) 
            l = mid;
        else 
            r = mid - 1;
    }
    return a[l];
}

bool check(double mid) {
    
}

// binarySearchC
// 实数域上的二分
double binarySearchC(double l, double r) {
    double eps = 1e-5;
    while(l + eps < r) {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
}

