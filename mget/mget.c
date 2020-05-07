#define _GNU_SOURCE

#include <unistd.h>
#include <sys/syscall.h>
#include <arpa/inet.h>

#define HOST argv[1]
#define PORT argv[2]
#define STDOUT 1
#define SOCK 3
#define GET "GET / HTTP/1.0\r\n\r\n"

static int _atoi(char *a)
{
    int i = 0;
    for (; *a; a++)
      i = i * 10 + *a - '0';
    return i;
}

static uint32_t _ipton4(char *ip)
{
  char result[4] = {0};
  char i;
  for (i = 0; *ip; ip++) {
    if (*ip == '.')
      i++;
    else
      result[i] = result[i] * 10 + *ip - '0';
  }
  return *((uint32_t *) result);
}

__attribute__((always_inline))
static inline void main(char* argv[])
{
  struct sockaddr_in addr;
  char c, state;
  char buffer[4096];

  syscall(SYS_socket, AF_INET, SOCK_STREAM, 0);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = _ipton4(HOST);
  addr.sin_port = htons(_atoi(PORT));
  syscall(SYS_connect, SOCK, (struct sockaddr *) &addr, sizeof(addr));

  syscall(SYS_write, SOCK, GET, sizeof(GET) - 1);

  state = 0;
  while (syscall(SYS_read, SOCK, &c, 1)) {
    if ((state % 2 == 0 && c == '\r') ||
        (state % 2 == 1 && c == '\n'))
      state++;
    else
      state = 0;
    if (state == 4)
      break;
  }

  while (syscall(SYS_write, STDOUT, buffer,
                 syscall(SYS_read, SOCK, buffer, sizeof(buffer))));
}

// __attribute__((force_align_arg_pointer))
void _start(int _0, int _1, int _2, int _3, int _4, int _5, char *argv0)
{
  // int argc = (int)(long)__builtin_return_address(0);;
  char **argv = &argv0;

  main(argv);
}
