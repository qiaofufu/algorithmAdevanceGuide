#include <bits/stdc++.h>
using namespace std;
const int N = 1E5+10;
int a[N];

void quick_sort(int l, int r) {
    if(l >= r) return;
    int key = a[l];
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[j] >= key) j --;
        swap(a[i], a[j]);
        while(i < j && a[i] <= key) i ++;
        swap(a[i], a[j]);
    }
    quick_sort(l, i - 1);
    quick_sort(i + 1, r);
}