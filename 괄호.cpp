#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <char> v;
int cnt;
void calc();
int main(){
	int t;
	char a;
	scanf("%d%c",&t,&a);
	while(t--){
		calc();
		cnt = 0;
	}
}
void calc(){
	char temp;
	while(1){
		scanf("%c",&temp);
		if(temp != '(' && temp != ')'){
			break;
		}
		else if(temp == '('){
			cnt++;
		}
		else{
			if(cnt == 0){
				printf("NO\n");
				while(1){
					scanf("%c",&temp);
					if(temp == '\n')break;
				}
				return;
			}
			else cnt--;
		}
	}
	if(cnt == 0)printf("YES\n");
	else printf("NO\n");
}