#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main(){
    SOCKET clientSocket; //creates socket structure
    WSDATA wsastructure; //creates WSADATA struct required for winsock init
    int result;
    int listeningPort = 9001;
    char ipAddr[] = "255.255.255.255";
    struct sockAddr_in clientAddr; //struct required by connect()
    char TXbuffer[500];
    char RXbuffer[500];
    result = WSAStartup(MAKEWORD(2,2), &wsastructure); //Initialize winsock
    //WSAStartup args: Winsock version, addr of data structure
    if(result != 0){
        printf("Winsock initialization failed\n");
        return 1;
    }
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    clientAddr.sin_family = AF_INET; //IPv4
    clientAddr.sin_port = htons(listeningPort); //nc port
    clientAddr.sin_addr.s_addr = inet_addr(ipAddr); //Server IP Address
    
    connect(clientSocket, (SOCKADDR*) &clientAddr, sizeof(clientAddr)) //connect to server
    recv(clientSocket, RXbuffer, sizeof(RXData), 0); //receive server data
    printf("From Server: %s\n, RXbuffer");
    send(clientSocket, TXbuffer, sizeof(TXbuffer), 0); //send data
    closesocket(clientSocket); //close socket connection
    WSACleanup();
    return 0;
}
/* Change listeningPort and IP to desired 
Compile and run exe on client*/
