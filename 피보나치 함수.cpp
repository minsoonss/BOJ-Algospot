//#include <cstdio>
//
//int zero;
//int one;
//int fibonacci(int i);
//int main(){
//	int n = 0;
//	scanf("%d",&n);
//	int input[50] ={-1,};
//	for(int i = 0; i < n; i++){
//		scanf("%d",&input[i]);
//	}
//	for(int i = 0; i < n; i++){
//		if(input[i]||-1){
//			fibonacci(input[i]);
//		}
//		printf("%d %d\n",zero,one);
//		zero = 0, one = 0;
//
//	}
//}
//int fibonacci(int n){
//	if(n == 0){
//		zero++;
//		return 0;
//	}
//	else if(n == 1){
//		one++;
//		return 0;
//	}
//	else{
//		fibonacci(n-1);
//		fibonacci(n-2);
//	}
//}
//

#include <cstdio>
 
int main(){
    int testcase = 0;
    int num;
    int arr[41] = {0,1,};
    scanf("%d",&testcase);
    for(int i = 2; i <= 40; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    for(int i = 0; i < testcase; i++){
        scanf("%d",&num);
        if(num == 0) printf("1 0\n");
        else printf("%d %d\n",arr[num-1],arr[num]);
    }
    return 0;
}