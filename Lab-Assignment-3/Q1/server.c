#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
int main()
{
  int server_socket;
  char server_message[256];
  char message_to_send[256];
  char filebuffer[10000];
  struct sockaddr_in client_address;
  socklen_t client_len;
  client_len = sizeof(client_address);

  FILE *fileptr;
  fileptr = fopen("directory.txt", "r");
  if(fileptr == NULL)
  {
    printf("error opening directory file\n");
    exit(1);
  }

  int error_check;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  error_check = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if(error_check == -1)
  {
    printf("Error binding\n");
    exit(1);
  }

  error_check = listen(server_socket, 3);
  if(error_check == -1)
  {
    printf("error in listening\n");
    exit(1);
  }

  int client_socket;

  client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_len);

  if(error_check == -1)
  {
    printf("error in accepting connection\n");
    exit(1);
  }

  char *addrtoken;
  int flag = 0;
  int copyflag = 0;

  error_check = recv(client_socket, server_message, sizeof(server_message), 0);

  while(fgets(filebuffer, 10000, (FILE *) fileptr))
  {
    addrtoken = strtok(filebuffer, " ");
    while(addrtoken != NULL)
    {
      if(flag == 1)
      {
        printf("%s\n", addrtoken);
        strcpy(message_to_send, addrtoken);
        flag = 0;
        copyflag = 1;
      }
      if (strcmp(addrtoken,server_message) == 0) {
        flag = 1;
      }
      addrtoken = strtok (NULL, " ");
    }
  }

  if (copyflag == 0) {
    strcpy(message_to_send,"Address not found\n");
  }

  error_check = send(client_socket, message_to_send, sizeof(message_to_send), 0);
  if(error_check == -1)
  {
    printf("error in sending\n");
    exit(1);
  }

  close(server_socket);

  return 0;
}