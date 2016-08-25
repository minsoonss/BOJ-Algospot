#include <cstdio>

int main(){
    char a,b;
    float score;
    scanf("%c",&a);
    if(a == 'F'){
        printf("0.0");
        return 0;
    }
    else if(a == 'A')score = 4;
    else if(a == 'B')score = 3;
    else if(a == 'C')score = 2;
    else if(a == 'D')score = 1;
    scanf("%c",&b);
    if(b == '+')score += 0.3;
    else if(b =='-')score -= 0.3;
    printf("%.1f",score);
}