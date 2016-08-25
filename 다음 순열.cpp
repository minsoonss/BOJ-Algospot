#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    vector <int> a(num);
    for(int i = 1; i < num+1; i++){
        a[i-1] = i;
    }
    do{
        for(int i = 0; i < num; i++){
            printf("%d ",a[i]);
        }
    }while(next_permutation(a.begin(),a.end()));
    
}