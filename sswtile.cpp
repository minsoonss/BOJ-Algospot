#include <stdio.h>

int gcd(int a, int b);
void calc(int a, int b, int c, int d);
int main(){
	int num1, num2;
	int inputnum;
	int gcdnum; //최대공약수
	scanf("%d",&inputnum);
	for(int i = 0; i < inputnum; i++){
		scanf("%d %d",&num1, &num2);
		gcdnum = gcd(num1,num2);
		calc(gcdnum, num1, num2,i+1);
	}
}
int gcd(int a, int b){
	if(b == 0)return a;
	else return gcd(b,a%b);
}
void calc(int a, int b, int c, int d){
	int result = b*c;
	printf("#testcase%d\n%d\n",d,(result/(a*a)));
}