# Ques 2

![](https://img.shields.io/badge/Language-C-orange.svg)

## Problem Statement

Please refer problem 1 mentioned above. In this program, you will convert your
previous program. The only logical change you need to make is to implement your
exchange of messages as a protocol. The protocol will be structured as follows (note,
a string of digits followed by a b means a binary number):
Requests:
Byte Number | Meaning with Code
0 | request code, 0000001(b) = name, 00001001(b) = number
1-n | request data
n+1 | end-of-request, 00000011(b) (ETX)

Replies:
Byte Number | Meaning with Code
0-n | reply data
n+1 | end-of-reply, 00000011(b) (ETX)

Note that the requests allow for both name and number matching, so you need to also
be able to match a name. Also note that the character string can contain any type of
byte oriented data, including binary representations of numbers. For example,

```c
short val;
char \*message;
message = &val;
send (sock, message, 2, 0);
```

## Instructions to run

1. Compile the files `server.c` and `client.c`. For this run the `compile.sh` script as follows  
   `./compile.sh`  
   If the above gives some error then use  
   `sudo bash compile.sh`  
   to run the script.
   Alternatively you can compile using the following commands:  
   `gcc server.c -o server`  
   `gcc client.c -o client`
2. Open 2 terminals, run server and client in the same order. Make sure to run server first.  
   `./server` (terminal 1)  
   `./client` (terminal 2)
3. Follow the on screen instructions.
