#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        bool d[101] = {false,};
        int ans = n;
        for(int j = 2; j <= n; j++){
            for(int k = 1; j*k <= n ;k++){
                d[j*k] = !d[j*k];
                if(!d[j*k])ans++;
                else ans--;
            }    
        }
        cout << ans << '\n';
    }
}