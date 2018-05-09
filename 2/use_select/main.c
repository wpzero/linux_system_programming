#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main() {
  struct timeval tv;
  fd_set readfds;
  int ret;

  for(;;) {

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(STDIN_FILENO+1, &readfds, NULL, NULL, &tv);
    if(ret == -1) {
      perror("select");
      return 1;
    } else if(!ret) {
      printf("%d seconds elapsed", TIMEOUT);
    }

    if(FD_ISSET(STDIN_FILENO, &readfds)) {
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
