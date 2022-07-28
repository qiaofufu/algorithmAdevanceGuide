const int N = 1E5+10;

int a[N],b[N];

void merge(int l, int r) {
    if(l == r) return;
    int mid = l + (r - l) / 2;
    merge(l, mid);
    merge(mid + 1, r);
    int i = l, j = mid + 1;
    for(int k = l; k <= r; k ++ )
        if(j > r || i <= mid && a[i] <= a[j]) b[k] = a[i ++];
        else b[k] = a[j ++];
    for(int k = l; k <= r; k ++ )
        a[k] = b[k]; 
}