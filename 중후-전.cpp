#include <cstdio>
 
const int N = 1e5 + 5;
int in[N], po[N], p[N];
 
void go( int il, int ir, int pl, int pr ){
    printf("%d ", po[pr]);
    int m = p[po[pr]];
    if( il <= m-1 )  go( il, m-1, pl, pl+(m-1)-il );
    if( m+1 <= ir ) go( m+1, ir, pr-(ir-m), pr-1 );
}
 
int main(){
    int n;
    scanf("%d", &n);
 
    for(int i=0; i<n; i++){
        scanf("%d", in+i);
        p[in[i]] = i;
    }
    for(int i=0; i<n; i++) scanf("%d", po+i);
    go( 0, n-1, 0, n-1 );
}

#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
 
#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn
 
#pragma warning(disable:4996)
using namespace std;
 
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
 
int IT_MAX;
const int MOD = 1000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
 
int in1[100050];
int ch[100050];
int in2[100050];
 
void aa(int s1, int e1, int s2, int e2) {
    if (s1 > e1) return;
    if (s1 == e1) {
        printf("%d ", in1[s1]);
        return;
    }
 
    int t = in2[e2];
    int t2 = ch[t];
    printf("%d ", t);
    aa(s1, t2-1, s2, s2 + t2-1 - s1);
    aa(t2 + 1, e1, e2 - e1 + t2, e2 - 1);
}
int main() {
    int N, i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &in1[i]);
        ch[in1[i]] = i;
    }
    for (i = 1; i <= N; i++) scanf("%d", &in2[i]);
    aa(1, N, 1, N);
    return 0;
}


#include <cstdio>
#include <cstring>
 
int l;
int str1[100005], str2[100005], find_root[100005];
 
void f(int s, int e, int s2, int e2){
    if(s > e) return;
    int root = str2[e2];
    printf("%d ",root);
    int pos = find_root[root];
    f(s,pos-1,s2,s2 + (pos-1-s));
    f(pos+1,e,s2+pos-s,e2-1);
}
int main(){
    scanf("%d",&l);
    for (int i=0; i<l; i++) {
        scanf("%d",&str1[i]);
        find_root[str1[i]] = i;
    }
    for (int i=0; i<l; i++) {
        scanf("%d",&str2[i]);
    }
    f(0,l-1,0,l-1);
}