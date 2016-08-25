#include <cstdio>

int main(){
	int arr[10000];
	int sum = 0;
	long long int max;
	int lineNum = 0;
	int inputNum;
	int outputNum;
	long long int submax = 0;
	long long int loopmax = 0;
	int result = 0;
	scanf("%d %d",&inputNum,&outputNum);
	for(int i = 0; i < inputNum; i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	max = sum/outputNum;
	loopmax = max/2;
	while(true){
		lineNum = 0;
		for(int i = 0; i < inputNum; i++){
			lineNum += arr[i]/loopmax;
		}
		if(lineNum >= outputNum){
			submax = loopmax;
			if(submax+1 == max){
				printf("%d",loopmax);//예외의경우
				return 0;
			}
		}
		else{
			//여기서 맥스값조절
			max = loopmax;
		}
		if(max+submax % 2 == 0)	loopmax = (max+submax)/2;
		else loopmax = (max+submax+1)/2;
	}
	//여기까지
	return 0;
}