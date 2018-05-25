/* This is a example about signal to string */
/* Best method is sys_siglist */

#include <signal.h>
#include <string.h>
#include <stdio.h>

int main() {
  char *sigstr = strsignal(SIGKILL);
  printf("%s\n", sigstr);
  printf("%s\n", sys_siglist[SIGCHLD]);
  psignal(SIGINT, "hello world");
  return 0;
}
