/* sum, avg sum with argc and argv */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])	//"argc" keeps number of args,
{									//"argv" keeps args as string
	double sum, avg, tmp;
	int i;
	
	printf("Number of args is: %d\n", argc);
	
	//initializing float variables
	sum = 0.0;
	avg = 0.0;
	
	for (i = 1; i < argc; i++)	//first arg, with index of 0 is a name of programm
	{
		tmp = atoi(argv[i]);
		sum += tmp;
	}
	
	avg = sum / (double)(argc - 1);	//casting "argc - 1" to "double"
	
	printf("Sum: %f\n", sum);
	printf("Average sum: %f\n", avg);
	
	return 0;
}
