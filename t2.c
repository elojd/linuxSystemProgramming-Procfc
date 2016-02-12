/* using procfs print PID & PPID of current process */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 100

int main()
{
  char buf[MAX_BUF], buf1[MAX_BUF], buf2[MAX_BUF];
  FILE * f;
  int i;
  
  for (i = 0; i < MAX_BUF; i++)
  {
    buf[i] = '\0';
    buf1[i] = '\0';
    buf2[i] = '\0';
  }
  
  f = fopen("/proc/self/status", "r");
  
  if (f == 0)
  {
    printf("Error.\n");
    return -1;
  }
  
  while (!feof(f))
  {
    fscanf(f, "%s", buf);
    
    if (strcmp(buf, "Pid:") == 0)
    {
      fscanf(f, "%s", buf1);
      printf("Pid of current process: %s\n", buf1);
    }
    
    if (strcmp(buf, "PPid:") == 0)
    {
      fscanf(f, "%s", buf2);
      printf("PPid of current process: %s\n", buf2);
    }
  }
  
  fclose(f);
  
  return 0;
}
