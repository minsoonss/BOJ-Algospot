#include <cstdio>

int arr[9][9];
bool check[9];
void input(); //스도쿠기초 입력
void search();
int main(){
	input();
	search();
	return 0;
}
void input(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%d",&arr[i][j]);
		}
	}
}
void search(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			check[j] = false;
		}
		for(int j = 0; j < 9; j++){
			if(arr[i][j] == 0){
				for(int k = j+1; k < 9; k++){
					if(arr[i][j] != 0)check[k] = true;
				}
			}
			else check[j] = true;
		}
	}
}