#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){

	int n=0;
	int *a=NULL;

	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n*2);

	for(int j=0;j<n;j++){
		a[j]=j+1;
	}

	for(int i=0;i<n*2;i+=2){
		printf("%d ",a[i]);
		if(a[n+1]==NULL)
			break;
		a[n+(i/2)]=a[i+1];
	}

	return 0;

}
//int main(){
//	int n;
//	cin >> n;
//	vector <int> v;
//	queue <int> q;
//	for(int i = 0; i < n; i++){
//		q.push(i+1);
//	}
//	while(q.size() != 1){
//		v.push_back(q.front());
//		q.pop();
//		int temp = q.front();
//		q.pop();
//		q.push(temp);
//	}
//	for(int i = 0; i < n-1; i++){
//		printf("%d ",v[i]);
//	}
//	printf("%d",q.front());
//}