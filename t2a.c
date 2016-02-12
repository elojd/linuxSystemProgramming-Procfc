/* print stats about process with PID 1 and memory map */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 500

int main()
{
  char buf[MAX_BUF];
  FILE * f;
  int i;
  
  for (i = 0; i < MAX_BUF; i++)
    buf[i] = '\0';
  
  f = fopen("/proc/1/status", "r");
  
  if (f == 0)
  {
    printf("Error.\n");
    return -1;
  }
  
  while (!feof(f))
  {
    fgets(buf, MAX_BUF, f);
    printf("%s", buf);
  }
  
  fclose(f);
  
  f = fopen("/proc/1/maps", "r");
  
  if (f == 0)
  {
    printf("Error.");
    return -1;
  }
  
  while (!feof(f))
  {
    fgets(buf, MAX_BUF, f);
    printf("%s", buf);
  }
  
  fclose(f);
  
  return 0;
}
