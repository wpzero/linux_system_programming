#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIME_OUT 100 * 1000
#define BUF_LEN 1024

int main() {
  int ret;
  struct pollfd fds[1];
  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;
  while(1) {
    ret = poll(fds, 1, TIME_OUT);
    if(ret == -1) {
      perror("poll");
      return 1;
    } else if(ret == 0) {
      printf("%d seconds elapsed\n", TIME_OUT);
    }
    if(fds[0].revents & POLLIN) {
      char buf[BUF_LEN+1];
      int len;
      len = read(STDIN_FILENO, buf, BUF_LEN);
      if(len == -1) {
        return 1;
      }
      if(len) {
        buf[len] = '\0';
        printf("%s", buf);
      } else {
        printf("recieve ctrl+d, and exit\n");
        return 0;
      }
    }
  }
  return 0;
}
