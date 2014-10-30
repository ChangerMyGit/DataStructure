#include "Vector.h"
#include <stdio.h>

int main(){
	int a[] = {2,3,4,1,5,6,7};
	Vector vec;
	initVector(&vec,10 * sizeof(int));
	vec.elem = a;
	vec.size = 7;
	bubbleSort2(&vec);
	printVector(&vec);
	return 0;
}