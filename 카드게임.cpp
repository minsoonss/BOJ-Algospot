#include <cstdio>
#include <cstring>
#define MAX2(a,b)	((a)>(b) ? (a) : (b))

int sum[1050];
int dp[1050][1050];
int enter[1050];
int num;
void init();
void calc();
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase--) {
		memset(dp,0,sizeof(dp));
		init();
		calc();
	}
	return 0;
}
void init(){
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		scanf("%d", &enter[i]);
		sum[i] = sum[i - 1] + enter[i];
	}
	for (int i = 1; i <= num; i++){
		dp[i][i] = enter[i];
	}
}
void calc(){
	int k = 0;
	for (int i = 1; i <= num; i++) {
		for (int j = i+k+1; j <= i+k+1; j++) {
			dp[i][j] = MAX2(sum[j] - sum[i] - dp[i+1][j]+enter[i], sum[j-1] - sum[i-1] - dp[i][j-1] + enter[j]);
			if(j == num){
				i = 0;
				k++;
			}
		}
		if(dp[1][num] != 0)break;
	}
	printf("%d\n", dp[1][num]);
}