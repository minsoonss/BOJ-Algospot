#include <stdio.h>

int checkpoint;
char board[20][20];
int width, height;
int count;
void entry(int a, int b);
void calc(int a, int b);
void recalc(int a, int b);
void incalc(int a, int b);
void outcalc(int a, int b);
void datainput();

int main(){
	int inputnum;
	char enter;
	bool check = false;
	scanf("%d",&inputnum);
	for(int i = 0; i < inputnum; i++){
		count = 0;
		checkpoint = 0;
		check = false;
		scanf("%d%d%c",&height,&width,&enter);
		datainput();
		for(int j = 0; j < height; j++){
			for(int k = 0; k < width; k++){
				if(board[j][k] == '.'){
					entry(j,k);
					check = true;
					break;
				}
			}
			if(check == true)break;
		}
		if(checkpoint == 0) printf("1");
		else printf("%d\n",count);
	}
}
void datainput(){ //기본게임판 입력
	char enter;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			scanf("%c",&board[i][j]);
		}
		scanf("%c",&enter);
	}
}
void entry(int a, int b){
	checkpoint = 1;
	calc(a,b);
	recalc(a,b);
	incalc(a,b);
	outcalc(a,b);
}
void calc(int a, int b){
	int check = 0;
	bool breakchceck = true;
	if(a < height-1 && b < width-1 && board[a+1][b] == '.' && board[a+1][b+1] == '.'){
		board[a][b] = '#';
		board[a+1][b] = '#';
		board[a+1][b+1] = '#';
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(board[i][j] == '#') check++;
			}
		}
		if(check == height*width)count++;
		else{
			for(int i = 0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(board[i][j] == '.'){
						entry(i,j);
						breakchceck = false;
						break;
					}
					

				}
				if(breakchceck == false)break;
			}
		}
		board[a][b] = '.';
		board[a+1][b] = '.';
		board[a+1][b+1] = '.';
	}
}
void recalc(int a, int b){
	bool breakchceck = true;
	int check = 0;
	if(b > 0 && a < height-1 && board[a+1][b] == '.' && board[a+1][b-1] == '.'){
		board[a][b] = '#';
		board[a+1][b] = '#';
		board[a+1][b-1] = '#';
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(board[i][j] == '#') check++;
			}
		}
		if(check == height*width)count++;
		else{
			for(int i = 0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(board[i][j] == '.'){
						entry(i,j);
						breakchceck = false;
						break;
					}
					
				}
				if(breakchceck == false)break;
			}
		}
		board[a][b] = '.';
		board[a+1][b] = '.';
		board[a+1][b-1] = '.';
	}
}
void incalc(int a, int b){
	bool breakchceck = true;
	int check = 0;
	if(a < height-1 && b < width-1 && board[a][b+1] == '.' && board[a+1][b+1] == '.'){
		board[a][b] = '#';
		board[a][b+1] = '#';
		board[a+1][b+1] = '#';
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(board[i][j] == '#') check++;
			}
		}
		if(check == height*width)count++;
		else{
			for(int i = 0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(board[i][j] == '.'){
						entry(i,j);
						breakchceck = false;
						break;
					}
					
				}
				if(breakchceck == false)break;
			}
		}
		board[a][b] = '.';
		board[a][b+1] = '.';
		board[a+1][b+1] = '.';
	}
}
void outcalc(int a, int b){
	bool breakchceck = true;
	int check = 0;
	if(a < height-1 && b < width-1 && board[a][b+1] == '.' && board[a+1][b] == '.'){
		board[a][b] = '#';
		board[a][b+1] = '#';
		board[a+1][b] = '#';
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(board[i][j] == '#') check++;
			}
		}
		if(check == height*width)count++;
		else{
			for(int i = 0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(board[i][j] == '.'){
						entry(i,j);
						breakchceck = false;
						break;
					}
					
				}
				if(breakchceck == false)break;
			}
		}
		board[a][b] = '.';
		board[a][b+1] = '.';
		board[a+1][b] = '.';
	}
}