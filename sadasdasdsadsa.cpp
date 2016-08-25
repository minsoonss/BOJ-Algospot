#include <iostream>
using namespace std;

template <typename T>
T sum(T* a, int b){
	T result = 0;
	for(int i = 0; i < b; ++i){
		result += a[i];
	}
	return result;
}

void main(){
	int intvals[] = {0,1,2};
	float floatvals[]={0.F,1.F,2.F};
	int inttotal = sum(intvals,3);
	float floattotal = sum(floatvals,3);
	cout << inttotal << endl;
	cout << floattotal << endl;
}
