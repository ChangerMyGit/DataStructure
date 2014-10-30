#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"

void initVector(Vector * vec , int capacity){
	vec->size = 0;
	vec->capacity = capacity;
	vec->elem = (int *)malloc(capacity);
}

void expand(Vector * vec){
	vec->elem = (int *)realloc(vec->elem , vec->capacity  << 1);
	vec->capacity <<=1; 
}

void insert(Vector * vec , int e){
	if(vec->size == vec->capacity / sizeof(int)){
		expand(vec);
	}  
	vec->elem[(vec->size)++] = e;
}

void insert2(Vector * vec , int e,int i){
	int len = vec->size;
	// �������
	if(i>0 && i< vec->size){
		while(len > i){
			vec->elem[len] = vec->elem[len-1];
			len --;
		}
		vec->elem[i] = e;
		vec->size++;
	} else {
		insert(vec,e);
	}
}

void deleteRange(Vector * vec,unsigned int lo,unsigned int high){
	if(lo == high);
	if(lo <= high && lo < vec->size && high < vec->size){
		high++;// �Ƶ�ɾ���ķ�Χ�� [lo,high] -> [lo,high);
		while(high < vec->size){
			vec->elem[lo++] = vec->elem[high++];
		}
		vec->size = vec->size - (high - lo);
	}
}

void deleteSingle(Vector * vec,unsigned int i){
	deleteRange(vec,i,i);
}

int find(Vector * vec,unsigned int i){
	if(i<vec->size)
		return vec->elem[i];
	return -1;
}

void reduplicate(Vector * vec){
	// Ĭ�ϴ�1��ʼ ����i֮ǰ�ļ��� ��������к�i�ظ��� ɾ��i��Ȼ��ȡi+1 �ٴαȽ�
	int j, i = 1;
	while(i<vec->size){
		for(j=0;j<i;j++){
			// ������ ɾ��i
			if(vec->elem[j] == vec->elem[i])
				deleteSingle(vec,i);
		}
		i++;
	}
}

int disortered(Vector * vec){
	int n = 0 ,i;
	for(i = 0;i<vec->size;i++){
		n += (vec->elem[i] > vec->elem[i+1]);
	}
	return n;
}

// ����������ȥ�� ��ʱ�临�Ӷ�ΪO(n)
int uniquify(Vector * vec){
	int i,j;
	for(i = 0 , j = 1;j<vec->size;j++){
		if(vec->elem[i] != vec->elem[j]){
		    vec->elem[++i] = vec->elem[j]; // ���Ƶ�i֮���Ԫ�� Ȼ��i��1
		}
	}
	vec->size = ++i;
	return j - i +1;
}

void vec_swap(int * x , int * y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(Vector * vec){
	int i , j;
	for(i = vec->size;i>0;i--)
		for(j = 1; j < i ; j++){
			if(vec->elem[j-1] >  vec->elem[j])
				vec_swap(&vec->elem[j-1],&vec->elem[j]);
		}
}

// lo = 0 hi = length
int binSearch(Vector * vec,int lo,int hi,int x){
	int mi;
	while(lo < hi){
		mi = (lo + hi) >> 1;
		if(vec->elem[mi] > x) hi = mi;
		else if(vec->elem[mi] < x) lo = mi + 1;
		else return mi;
	}
	return -1;
}

// lo = 0 hi = length-1
int binSearch2(Vector * vec,int lo,int hi,int x){
	int mi;
	while(lo <= hi){
		mi = (lo + hi) >> 1;
		if(vec->elem[mi] > x) hi = mi-1;
		else if(vec->elem[mi] < x) lo = mi + 1;
		else return mi;
	}
	return -1;
}

// ���ֲ��� ������ҷ�֧��ƽ�������
// ÿ��ֻ��������֧ x < a[mi] [lo,mi) a[mi] <= x [mi+1 , hi)
int binSearch3(Vector * vec,int x){
	int lo = 0 , mi , hi = vec->size;
	if(x > vec->elem[hi-1] || x <  vec->elem[lo]) 
	    return (x > vec->elem[hi-1]) ? hi : lo-1;
	while(lo < hi){
		mi = (lo + hi) >> 1;
		(x < vec->elem[mi]) ? (hi = mi):(lo = mi + 1);
	}
	return --lo; // ����Ԫ���������������һ��Ԫ��
}

void fibonacci(int *f){
	int i;
	f[0] = 0;
	f[1] = 1;
	for(i = 2 ;i < MAX_SIZE; i++){
		f[i] = f[i-1] + f[i-2];
	}
}

int fibonacciSearch(Vector * vec,int x){
	int lo = 0 ,hi = vec->size ,mi , k = 0;
	int f[MAX_SIZE];
    fibonacci(f);
	while(vec->size > f[k]-1)
		k++;
	while(lo < hi){
	    mi = lo + f[k-1] - 1;
		if(vec->elem[mi] > x){
			hi = mi;
			k -=1;
		} else if(vec->elem[mi] < x){
		    lo = mi + 1;
			k -=2;
		} else 
			return mi;
	}
	return -1;
}

// ð������Ľ���
void bubbleSort(Vector * vec){
	int hi = vec->size;
	// ���������Ƴ� ʹ��lo �� lo - 1 �Ƚ� ����lo��ʼ��Ϊ1
	while(!bubble(vec,1,hi--)); // ����ɨ��ֱ��ȫ��
}

int bubble(Vector * vec,int lo,int hi){
	int sorted = TRUE;
	for(;lo < hi; lo++){
		if(vec->elem[lo-1] > vec->elem[lo]){
			vec_swap(&vec->elem[lo-1],&vec->elem[lo]);
			sorted = FALSE;
		}
	}
	return sorted;
}

void printVector(Vector * vec){
	int i = 0;
	for(;i<vec->size;i++)
		printf("%d ",vec->elem[i]);
}

