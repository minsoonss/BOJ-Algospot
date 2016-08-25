#include <cstdio>

int arr[501][501];
int main(){
	int size = 0;
	scanf("%d",&size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i = size-1; i > 0; i--){
		for(int j = i-1; j >= 0; j--){
			arr[i-1][j] += arr[i][j] > arr[i][j+1] ? arr[i][j] : arr[i][j+1];
		}
	}
	printf("%d",arr[0][0]);
}