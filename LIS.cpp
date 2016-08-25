#include <cstdio>

int calc(int *arr, int num);
int main(){
	int testcase = 0;
	int num;
	scanf("%d",&testcase);
	for(int i = 0; i < testcase; i++){
		int arr[500] = {0,};
		scanf("%d",&num);
		for(int j = 0; j < num; j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n",calc(arr,num));
	}
}
int calc(int *arr, int num){
	int brr[500];
	int crr[500] = {0,};
	int max = 0;
	for(int i = 0; i < num; i++){
		brr[i] = 1;
	}
	for(int i = 0; i < num-1; i++){
		for(int j = i+1; j < num; j++){
			if(arr[i] < arr[j]){
				if(arr[i] < crr[j] || crr[j] == 0){
					if(brr[i]+1 >= brr[j]){
						brr[j] = brr[i]+1;
						crr[j] = arr[i];
					}
					else if(arr[i] < crr[j] && brr[i] > brr[j]){
						brr[j]++;
						crr[j] = arr[i];
					}
					
				}
				else if(arr[i] > crr[j] && brr[j] >1){
					crr[j] = arr[i];
					brr[j]++;
				}
			}
		}
	}
	max = brr[0];
	for(int i = 0; i < num; i++){
		if(brr[i] > max)max = brr[i];
	}
	return max;
}