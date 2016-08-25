#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int ans,inp;
	char arr[16];
	scanf("%d %d%c",&ans,&inp);
	for(int i = 0; i < inp; i++){
		scanf("%c ",&arr[i]);
	}
	sort(arr,arr+inp);

}