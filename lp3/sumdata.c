#include "sumdata.h"
int x[5] = {1,2,3,4,5};

int sum(int sum_events){
	int i;
	int acc = 0;

for( i = 0; i < 5; i++)
	if((!sum_events)||(!(x[i]%2)))
	acc += x[i];

return acc;
} 

