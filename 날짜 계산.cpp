#include <cstdio>

int main(){
	int e, s, m;
	int le=0,ls=0,lm=0;
	int count = 0;
	scanf("%d %d %d",&e,&s,&m);
	while(1){
		if(le == e && ls == s && lm == m)break;
		le++;
		ls++;
		lm++;
		count++;
		if(le == 16)le = 1;
		if(ls == 29)ls = 1;
		if(lm == 20)lm = 1;
	}
	printf("%d",count);
}