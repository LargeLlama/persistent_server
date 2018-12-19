#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  printf("[server] waiting for data...\n");

  while(from_client)
  {
	char data[BUFFER_SIZE];
	read(from_client, data, BUFFER_SIZE);
	printf("[server] received %s from client :3\n", data);
  }
}
