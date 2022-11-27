#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#define SERVER_PORT 5434
#define MAX_PENDING 5
#define MAX_LINE 256
int main()
{
    struct sockaddr_in server_addr, client_addr;
    char buf[MAX_LINE];
    socklen_t len=sizeof(client_addr);
    int s, new_s;
    /* build server address data structure */
    bzero((char *)&server_addr, sizeof(server_addr)); //clearing memory
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;   // opening server to all ip
    server_addr.sin_port = htons(SERVER_PORT);  // storing port number


    /* setup passive open */
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation unsuccessful");
        exit(1);
    }
    /*bondong the socket with server address*/
    if ((bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr))) < 0)
    {
        perror("Error binding");
        exit(1);
    }
    listen(s, MAX_PENDING);
    /* wait for connection, then receive and print text */
    bzero((char *)&client_addr, sizeof(client_addr));
    if ((new_s = accept(s, (struct sockaddr *)&client_addr, &len)) < 0)
    {
        perror("simplex-talk: accept");
        exit(1);
    }

    FILE *fp;
    int words;
    read(new_s,&words,sizeof(int));
    printf("No. of words in the file received: %d\n", words);
    fp=fopen("server_file.txt", "a");
    // len = recv(new_s, &words, sizeof(int), 0);
    int temp=0;
    while(temp!=words)
    {
       int len1 = recv(new_s, buf, sizeof(buf), 0);
       fprintf(fp, "%s ", buf);
       temp++;
    }

    close(new_s);
}
