#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int anum;
int bnum;
int arr[1000000];
int brr[1000000];
int result[2000000];
void hap();
int main(){
	scanf("%d %d",&anum,&bnum);
	for(int i = 0; i < anum; i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < bnum; i++){
		scanf("%d",&brr[i]);
	}
	hap();
	for(int i = 0; i < anum+bnum; i++){
		printf("%d ",result[i]);
	}
}
void hap(){
	int c = 0;
	int i = 0;
	int j = 0;
	while(i < anum && j < bnum){
		if(arr[i] > brr[j])result[c++] = brr[j++];
		else result[c++] = arr[i++];
	}
	if(i < anum){
		for(int index = i; index < anum; index++){
			result[c++] = arr[index];
		}
	}
	else if(j < bnum){
		for(int index = j; index < bnum; index++){
			result[c++] = brr[index];
		}
	}
}