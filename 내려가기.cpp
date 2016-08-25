#include <cstdio>
#define MIN1(a,b) ((a) < (b) ? (a) : (b))
#define MAX1(a,b) ((a) > (b) ? (a) : (b))
#define MIN2(a,b,c) ((MIN1(a,b)) < (c) ? (MIN1(a,b)) : (c))
#define MAX2(a,b,c) ((MAX1(a,b)) > (c) ? (MAX1(a,b)) : (c))
int maxmatrix[3][100000];
int minmatrix[3][100000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d",&maxmatrix[0][i],&maxmatrix[1][i],&maxmatrix[2][i]);
		minmatrix[0][i] = maxmatrix[0][i];
		minmatrix[1][i] = maxmatrix[1][i];
		minmatrix[2][i] = maxmatrix[2][i];
	}
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < 3; j++){
			if(j == 0){
				maxmatrix[j][i] += MAX1(maxmatrix[j][i+1],maxmatrix[j+1][i+1]);
				minmatrix[j][i] += MIN1(minmatrix[j][i+1],minmatrix[j+1][i+1]);
			}
			else if(j == 1){
				maxmatrix[j][i] += MAX2(maxmatrix[j-1][i+1],maxmatrix[j][i+1],maxmatrix[j+1][i+1]);
				minmatrix[j][i] += MIN2(minmatrix[j-1][i+1],minmatrix[j][i+1],minmatrix[j+1][i+1]);
			}
			else{
				maxmatrix[j][i] += MAX1(maxmatrix[j][i+1],maxmatrix[j-1][i+1]);
				minmatrix[j][i] += MIN1(minmatrix[j][i+1],minmatrix[j-1][i+1]);
			}
		}
	}
	printf("%d %d",MAX2(maxmatrix[0][0],maxmatrix[2][0],maxmatrix[1][0]),MIN2(minmatrix[0][0],minmatrix[2][0],minmatrix[1][0]));
}