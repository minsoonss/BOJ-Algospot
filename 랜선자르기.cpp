#include <cstdio>
int a[10000];
int n,m;
bool check(int x) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += a[i]/x;
    }
    return cnt >= m;
}
int main() {
    scanf("%d %d",&n,&m);
    int max = 0;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if (max < a[i]) {
            max = a[i];
        }
    }
    int ans = 0;
    int l = 1;
    int r = max;
    while (l <= r) {
        int mid = l+(r-l) / 2;
        if (check(mid)) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}