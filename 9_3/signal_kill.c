/* This is an example about singal kill */
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void int_handler() {
  printf("Received the signal");
  exit(EXIT_SUCCESS);
}

int main() {
  pid_t p_id = fork();
  if(p_id) {
    signal(SIGUSR1, int_handler);
  }else {
    kill(p_id, SIGUSR1);
  }
  wait(NULL);
  return 0;
}
