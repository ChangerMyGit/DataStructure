#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	unsigned int length = 0;
	int i ,sum = 0;
	for(i = 0;i<=length-1;i++)
		sum += a[i];
    printf("%d",sum);
	return 0;
}