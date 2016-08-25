#include <stdio.h>

int T,M,N,X,Y;

int main()
{
	int i,j,x;
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d%d",&M,&N,&X,&Y);
		for (i=0;i<M;i++){
			x = (N*i+Y)%M;
			if (!x) x = M;
			if (x == X) break;
		}
		if (i == M) puts("-1");
		else{
			printf("%d\n",i*N+Y);
		}
	}
}