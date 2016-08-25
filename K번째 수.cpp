#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int v[5000000];
int main(){
    
    int num;
    int cnt;
    scanf("%d %d",&num,&cnt);
    for(int i = 0; i < num; i++){
        scanf("%d",&v[i]);        
    }
	nth_element(v,v+cnt-1,v+num);
    printf("%d",v[cnt-1]);
    
}