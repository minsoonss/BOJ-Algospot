#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int L , C ;
	int i=0,j=0,swap; //�ε����� ����?
	char arr[15]; 
	int ja=0;
	int mo=0;
	int cnt=0;
	char space; //�����̽���
	int index[15]={0,}; //
	scanf("%d %d\n",&C,&L);
	for(i=0;i<L;i++){
		scanf("%c%c",&arr[i],&space);
	}
	for(i=0;i<L-1;i++){
		for(j=0;j<L-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = swap;
			}
		}
	} //����
	for(i=0;i<C;i++){
		index[i]=i;
	}
	while(index[0] <=L - C){
		for(i=0;i<C;i++){
			switch(arr[index[i]]){
			case 'a':
				mo++;
				break;
			case 'i':
				mo++;
				break;
			case 'o':
				mo++;
				break;
			case 'u':
				mo++;
				break;
			case 'e':
				mo++;
				break;
			default:
				ja++;
			}
		}
		for(i=0;i<C;i++){
			if(mo>0 && ja>1)printf("%c",arr[index[i]]);
		}
		if(mo >0 && ja>1)printf("\n");
		mo=0;
		ja=0;
		cnt=0;
		index[C-1]++;//��¸����� index
		for(i=C-1;i>0;i--){
			if(index[i]==L-cnt){
				index[i-1]++;
				index[i] = index[i-1] +1;  //�̺κ� ����
				for(j=i;j<=C;j++){
					index[j]=index[j-1]+1;
				}
			}
			else{
				break;
			}
			cnt++;
		}

	}
	return 0;
}