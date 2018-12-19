#include "pipe_networking.h"
#include <readline/readline.h>

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while(1)
  {
	char data[BUFFER_SIZE];
	
	printf("[client] input something: ");
	strncpy(data, readline(""), BUFFER_SIZE);
	write(to_server, data, BUFFER_SIZE);
	printf("\n[client] sent %s to server\n", data);
  }

}
