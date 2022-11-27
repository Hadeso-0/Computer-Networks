#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#define SERVER_PORT 5434

#define MAX_LINE 256
int main(int argc, char *argv[])
{
    FILE *fp;
    struct hostent *hp;
    struct sockaddr_in sin;
    char *host;
    char buf[MAX_LINE];
    int s;
    socklen_t len=sizeof(sin);
    if (argc == 2)
    {
        host = argv[1];
    }
    else
    {
        fprintf(stderr, "host already in use\n");
        exit(1);
    }
    /* translate host name into peer's IP address */
    hp = gethostbyname(host);
    if (!hp)
    {
        fprintf(stderr, "Error Connecting: unknown host: %s\n", host);
        exit(1);
    }

    /* build address data structure */
    bzero((char *)&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
    sin.sin_port = htons(SERVER_PORT);
    /* active open */
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("simplex-talk: socket");
        exit(1);
    }
    if (connect(s, (struct sockaddr *)&sin, len) < 0)
    {
        perror("simplex-talk: connect");
        close(s);
        exit(1);
    }
  
 
    int words = 0;
    char c;
    fp=fopen("client_file.txt","r");
    while(fscanf(fp,"%s",buf)!=EOF)
    words++;
     printf("No. of words in the file transmitted: %d\n", words);
    write(s, &words, sizeof(int)); 
    rewind(fp);
    char ch;
    while(ch!=EOF)
    {
        fscanf(fp, "%s" , buf);
        len = send(s, &buf, sizeof(buf), 0);
        if (len == -1)
        {
            printf("error sending message\n");
            exit(1);
        }   
        ch=fgetc(fp);     
    }

    close(s);
}

