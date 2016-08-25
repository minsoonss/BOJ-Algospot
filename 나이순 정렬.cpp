#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

typedef struct info{
	string s;
	int age;
	int cnt;
}info;
bool compare(const info& a,const info& b){
	if(a.age < b.age)return true;
	else if(a.age == b.age){
		if(a.cnt < b.cnt)return true;
		else return false;
	}
	else return false;
}
info a[100000];
int main(){
	int num;
	scanf("%d",&num);
	for(int i = 0; i < num; i++){
		scanf("%d ",&a[i].age);
		cin >> a[i].s;
		a[i].cnt = i;
	}
	sort(a,a+num,compare);
	for(int i = 0; i < num; i++){
        printf("%d %s\n",a[i].age,a[i].s);        
	}
}