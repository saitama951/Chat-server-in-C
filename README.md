# Chat-server-in-C
A simple chat server in C using Threads
BEFORE COMPILING THE PROGRAM
------------------------------
1.Make sure that the server IP is correct in the client.c program
2.Make sure the network ID of the server and client should be same and host ID should different in the IP

COMPILING THE PROGRAM
------------------------------
1.For the server program link the necessary library and ignore the warnings
    ex- gcc server.c -o server.out -lpthread -w
2.similarly for the client program 

WHILE EXECUTING THE PROGRAM
------------------------------
1.Dont forcefully terminate the program by using ctrl+c or ctrl+z 
