# Ques 1

![](https://img.shields.io/badge/Language-C-orange.svg)

## Problem Statement

Write a simple client-server program using stream socket that provides chat
facility. Your application allows a user on one machine to type in and send text
to a user on another machine over the socket.

## Instructions to run client server chat program

1. Compile client and server using gcc.  
   `gcc client.c -o client`  
   `gcc server.c -o server`
1. Open two terminals, run server in one and client in the other. Make sure to run server before client.  
   `./server`  
   `./client`
1. Now the communication between client can server can proceed. Send a message from client, it will be received on server and same happens from server to client.
1. To end the chat, send `exit` as a message.
