#include <stdio.h>

FILE *input = fopen("tree.inp","rt");
FILE *output = fopen("tree.out","wt");

void pre(int arr1[13000], int arr2[13000], int index, int size, int start, int test){ //전위구하는함수
	int i=0,j=0,k=0;
	int root=0;
	int left1[13000];
	int left2[13000];
	int right1[13000];
	int right2[13000];
	index=0;

	if( size ==0 ){
		return;
	}
	
	else{
		root = arr2[size-1];

		for(i=0;i<size;i++){ // 중위에서 루트인덱스값찾기
			if( arr1[i] == root ){
				i=size;
			}
			index++;
		}


		for(i=0;i<index-1;i++){
			left1[k] = arr1[i];
			left2[k] = arr2[i];
			k++;
		}
		if( index ==1 ){
			left2[k]= arr2[i];
		}

		for(i=index-1;i<size-1;i++){
			right1[j] = arr1[i+1];
			right2[j] = arr2[i];
			j++;
		}


		fprintf(output,"%d\n",root);

		pre(left1,left2, index, index-1, 0, test); //left
		pre(right1, right2, index, size-index, index+1, test); //right


	}
	
}

void post(int arr1[13000], int arr2[13000], int index, int size, int start, int test){ //전위구하는함수
	int i=0,j=0,k=0;
	int root=0;
	int left1[13000];
	int left2[13000];
	int right1[13000];
	int right2[13000];
	index=0;

	if( size ==0 ){
		return;
	}

	else{
		root = arr2[0];

		for(i=0;i<size;i++){ // 중위에서 루트인덱스값찾기
			if( arr1[i] == root ){
				i=size;
			}
			index++;
		}


		for(i=0;i<index-1;i++){
			left1[k] = arr1[i];
			left2[k] = arr2[i+1];
			k++;
		}

		if( index ==1 ){
			left2[k]= arr2[i];
		}

		for(i=index-1;i<size-1;i++){
			right1[j] = arr1[i+1];
			right2[j] = arr2[i+1];
			j++;
		}



		
		
		post(left1,left2, index, index-1, 0, test); //left
		post(right1, right2, index, size-index, index+1, test); //right
		fprintf(output,"%d\n",root);
	

	}
	
}


int main(){

	int i=0,j=0,k=0;
	int node_num=0;
	int test1=0,test2=0;
	int temp=0;
	int arr1[13000]={0,};
	int arr2[13000]={0,};

	fscanf(input,"%d",&node_num);

	fscanf(input,"%d",&test1);
	if( test1 == 0 ){
		for(i=0;i<node_num;i++){
			fscanf(input,"%d",&arr1[i]);
		}
	}
	else{
		for(i=0;i<node_num;i++){
			fscanf(input,"%d",&arr2[i]);
		}
	}
	fscanf(input,"%d",&test2);
	if( test2 == 0 ){
		for(i=0;i<node_num;i++){
			fscanf(input,"%d",&arr1[i]);
		}
	}
	else{
		for(i=0;i<node_num;i++){
			fscanf(input,"%d",&arr2[i]);
		}
	}

	if( test1 == 1 || test2 == 1){
		pre(arr1, arr2, 0, node_num, 0,  0);
	}
	else if( test2 == -1 || test2 == -1 ){
		post(arr1, arr2, 0, node_num, 0, 1);
	}



	

	return 0;
}