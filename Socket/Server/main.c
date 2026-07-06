#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(){
    int serverSocket; //Creating socket
    int clientSocket; //Accepts connection
    int listeningPort = 9001;
    char ipAddr[] = "255.255.255.255"; 
    struct sockAddr_in serverAddr; //Structure required by bind()
    char TXbuffer[500]; //Holds TX messages
    char RXbuffer[500]; //Holds RX messages
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); //creates TCP socket
    //socket args: Specify IPv4, Specified TCP socket, 0. [socket family, type, protocol]
    
    serverAddr.sin_family = AF_INET; //Specifies IPv4
    serverAddr.sin_port = htons(listeningPort); //network listening port
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr); //server address
    
    bind(serverSocket, (struct serverAddr*) &serverAddr, sizeof(serverAddr)); //Bind server
    //bind args: socket, required struct address, size in bytes of struct
    listen(serverSocket, 5); //listens to 5 connections
    
    clientSocket = accept(serverSocket, NULL, NULL); //accept incoming connections
    printf("Client Connected!\n");
    send(clientSocket, TXbuffer, sizeof(TXbuffer), 0); //Send msg to client
    recv(clientSocket, RXbuffer, sizeof(RXbuffer), 0); //Receive msg from client
    printf("From Client: %s", RXbuffer);
    close(serverSocket);
    return 0;


/* Change listening port and IP to desired
Compile and run on server, 
spawn netcat listening terminal with same listening port */
