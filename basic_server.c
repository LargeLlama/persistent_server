#include "pipe_networking.h"

#define SIGINT 2
void sighandler(int n)
{
	if (n == SIGINT)
	{
		remove("mario");
		printf("[server] piped removed, exiting!\n");
		exit(0);
	}
}

int main() {

  int to_client;
  int from_client;
  char data[BUFFER_SIZE];

  printf("[server] waiting for data...\n");

  while(1)
  {
	  from_client = server_handshake( &to_client );

	  while(read(from_client, data, BUFFER_SIZE))
	  {
		printf("[server] received %s from client :3\n", data);

		for(int i = 0; i < strlen(data); i++)
			data[i] += 5;

		write(to_client, data, BUFFER_SIZE);
		printf("[server] sending back %s\n", data);
	  }
	  printf("[server] client disconnected\n");
  }
}
