#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

#define IS_NEGATIVE(T) T < 0

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

int main(void) {
  const int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (IS_NEGATIVE(server_fd)) {
    fprintf(stderr, "Socket: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  sockaddr_in addr = {0};

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  if (IS_NEGATIVE(bind(server_fd, (sockaddr *)&addr, sizeof(addr)))) {
    fprintf(stderr, "Bind: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  listen(server_fd, 10);

  while (true) {
    const int client_fd = accept(server_fd, NULL, NULL);
    if (IS_NEGATIVE(client_fd)) {
      fprintf(stderr, "Accept: %s", strerror(errno));
      continue;
    }

    char buffer[256] = {0};

    recv(client_fd, buffer, 256, 0);

    const char *const file = buffer + 5;
    *strchr(file, ' ') = 0;

    const int opened_fd = open(file, O_RDONLY);

    sendfile(client_fd, opened_fd, 0, 256);

    close(opened_fd);
    close(client_fd);
  }
}
