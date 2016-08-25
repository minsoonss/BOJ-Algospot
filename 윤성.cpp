#include <cstdio>

int main(){
	int a = 10;
	int b;
	int *c = &b;
	b = a++;
	b += 10;
	printf("%d %d %d",a,b,c);
}