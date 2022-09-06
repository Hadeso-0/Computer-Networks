1. socket: creates an endpoint for communication and returns a file descriptor that refers to that endpoint. The file descriptor returned by a successful call will be the lowest-numbered file descriptor not currently open for the process.
   Command:

```c
int socket(int domain, int type, int protocol);
```

2. bind: When a socket is created with socket(), it exists in a name space (address family) but has no address assigned to it. bind() assigns the address specified by `addr` argument to the socket referred to by the file descriptor `sockfd`.
   Command:

```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

3. connect: Initiate a connection on a socket. system call connects the socket referred to by the file descriptor `sockfd` to the address specified by `addr`.
   Command:

```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

4. listen: It marks the socket referred to by `sockfd` as a passive socket, that is, as a socket that will be used to accept incoming connection requests using accept().
   Command:

```c
int listen(int sockfd, int backlog);
```

5. accept: accept the incoming connection requests on a socket.
   Command:

```c
int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen);
```

6. send: send a message on a socket.
   Command:

```c
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```

7. recv: receive a message from a socket.
   Command:

```c
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```

8. sendto: The sendto() function shall send a message through a connection-mode or connectionless-mode socket. If the socket is connectionless-mode, the message shall be sent to the address specified by dest_addr. If the socket is connection-mode, dest_addr shall be ignored.
   Command:

```c
ssize_t sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
```

9. recvfrom: The recvfrom() function shall receive a message from a connection-mode or connectionless-mode socket. It is normally used with connectionless-mode sockets because it permits the application to retrieve the source address of received data.
   Command:

```c
ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);
```

10. close: close() closes a file descriptor, so that it no longer refers to any file and may be reused.
    Command:

```c
int close(int socket);
```

11. shutdown: The shutdown() call causes all or part of a full-duplex connection on the socket associated with sockfd to be shut down.
    Command:

```c
int shutdown(int socket, int how);
```

12. fork: fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.
    Command:

```c
pid_t fork();
```
