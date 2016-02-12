/* print stats of all partitions on system */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 100

int main()
{
  char buf[MAX_BUF];
  char name[MAX_BUF];
  char size[MAX_BUF];
  FILE * f;
  int i, j;
  
  f = fopen("/proc/partitions", "r");
  
  if (!f)	//"!f" same as "f == 0"
  {
    printf("Error.\n");
    return -1;
  }
  
  j = 0;
  
  while (!feof(f))
  {
    if (j > 1)
    {
      for (i = 0; i < 4; i++)
      {
	fscanf(f, "%s", buf);
	
	if (i == 2)
	  fscanf(f, "%s", size);
	else if (i == 3)
	  fscanf(f, "%s", name);
	else
	  fscanf(f, "%s", buf);
      }
      printf("%s\t%s\n", name, size);
    }
    else
      fgets(buf, MAX_BUF, f);
    
    j++;
  }
  
  fclose(f);
  
  return 0;
}
