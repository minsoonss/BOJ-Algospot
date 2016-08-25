#include <iostream>
#include <stack>
#include <string>
using namespace std;

int light;
char prev = NULL;
stack <char> st;
int calc(string s);
int main(){
	string s;
	cin >> s;
	cout << calc(s);
}
int calc(string s){
	int size = s.length();
	int ans = 0;
	for(int i = 0; i < size; i++){
		if(s[i] == '('){
			st.push(s[i]);
			if(s[i+1] != ')')light++;
		}
		else{
			st.pop();
			if(s[i-1] != ')'){
				ans += st.size();
				printf("¹Ùº¸");			}
		}
	}
	ans += light;
	return ans;
}