#include "Vector.h"
#include <stdio.h>

int main(){
	int i;
	Vector vec;
	initVector(&vec,10 * sizeof(int));
	for(i=1;i<=10;i++)
		insert(&vec,i);
	for(i=1;i<=10;i++)
		insert(&vec,i);
	deleteSingle(&vec,2);
	printVector(&vec);
	printf("\n");
	//insert2(&vec,16,2);
	//deleteRange(&vec,1,7);
	//deleteSingle(&vec,9);
	reduplicate(&vec);
	printVector(&vec);
	//printf("\n%d\n",find(&vec,8));
	return 0;
}