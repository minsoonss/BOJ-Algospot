#include <cstdio>
#include <vector>
using namespace std;
vector <int> bi;
int arr[10000];
int a;
void binary(int num);
int main(){
	scanf("%d",&a);
	for(int i = 0; i < 10; i++){
		arr[i] = 567;
	}
	binary(a);
	return 0;
}
void binary(int num){
	if(num == 0){
		for(int i = 0; i < a; i++){
			printf("%d",arr[i]);
		}
		printf("\n");
		return;
	}
	arr[a-num] = 0;
	binary(num-1);
	arr[a-num] = 1;
	binary(num-1);
}