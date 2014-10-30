#include "Vector.h"
#include <stdio.h>

int main(){
	int i;
	Vector vec;
	initVector(&vec,10 * sizeof(int));
	for(i=1;i<=13;i++)
		insert(&vec,i);
	for(i=1;i<=13;i++)
		insert(&vec,i);
	for(i=1;i<=5;i++)
		insert(&vec,i);
	//deleteSingle(&vec,2);
	printVector(&vec);
	printf("\n");
	//insert2(&vec,16,2);
	//deleteRange(&vec,1,7);
	//deleteSingle(&vec,9);
	//reduplicate(&vec);
	//printVector(&vec);
	//sort(&vec);
	bubbleSort(&vec);
	bubbleSort(&vec);
	printVector(&vec);
    printf("\n");
	uniquify(&vec);
	printVector(&vec);
	printf("\n");
	printf("%d\n",binSearch(&vec,0,13,7));
	printf("%d\n",binSearch2(&vec,0,12,7));
	printf("%d\n",fibonacciSearch(&vec,13));
	printf("%d\n",binSearch3(&vec,2));
	return 0;
}