/* print stats about all devices on system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 100

int main()
{
  char buf[MAX_BUF];
  int i;
  FILE * f;
  int printFlag = 0;
  
  for (i = 0; i < MAX_BUF; i++)
    buf[i] = '\0';
  
  f = fopen("/proc/devices", "r");
  
  if (!f)
  {
    printf("Error.");
    return -1;
  }
  
  while (!feof(f))
  {
    fgets(buf, MAX_BUF, f);
    
    if (strstr(buf, "Block devices:"))
      printFlag = 1;
    
    if (printFlag == 1)
      printf("%s", buf);
  }
  
  fclose(f);
  
  return 0;
}
