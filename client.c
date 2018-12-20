#include "pipe_networking.h"
#include <readline/readline.h>

int main() {

  int to_server;
  int from_server;
  char data[BUFFER_SIZE];

  from_server = client_handshake( &to_server );

  while(1)
  {
	printf("[client] input something: ");
	strncpy(data, readline(""), BUFFER_SIZE);

	write(to_server, data, BUFFER_SIZE);
	printf("\n[client] sent %s to server\n", data);

	read(from_server, data, BUFFER_SIZE);
	printf("[client] got back %s\n", data);
  }

}
