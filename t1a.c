/* summing untill input is "END" */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	double sum, avg, tmp;
	int i;
	char tmp1[10];
	
	sum = 0.0;
	avg = 0.0;
	i = 0;
	
	printf("Type a number or END for quit summing\n");
	scanf("%s", &tmp1);	//reading from standard input
	i++;
	
	while (strcmp(tmp1, "END") != 0)
	{
		tmp = atof(tmp1);
		sum += tmp;
		i++;
		
		scanf("%s", &tmp1);
	}
	
	avg = sum / (double)(i - 1);
	
	printf("Sum is: %f\n", sum);
	printf("Avg sum is: %f\n", avg);
	
	return 0;
}
