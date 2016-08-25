#include <cstdio>
#include <algorithm>
using namespace std;

int anum;
int bnum;
int arr[500001];
int brr[500001];
int result[500001];
int check;
void search(int start, int finish, int num);
int main(){
	scanf("%d",&anum);
	for(int i = 0; i < anum; i++)scanf("%d",&arr[i]);
	sort(arr,arr+anum);
	scanf("%d",&bnum);
	for(int i = 0; i < bnum; i++)scanf("%d",&brr[i]);
	for(int i = 0; i < bnum; i++){
		check = 0;
		search(0,anum,brr[i]);
		result[i] = check;
	}
	for(int i = 0; i < bnum; i++)printf("%d ",result[i]);
}
void search(int start, int finish, int num){
	//ÀÌºĞÅ½»ö
	if(start >= finish)return;
	if(arr[(start+finish)/2] == num){
		check++;
	}
	if(arr[(start+finish)/2] <= num){
		search((start+finish)/2+1,finish,num);
	}
	if(arr[(start+finish)/2] >= num){
		search(start,(start+finish)/2,num);
	}
}