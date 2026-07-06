/* Compile and run exe on client*/

#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main(){
    SOCKET clientSocket; //creates socket structure
    WSDATA wsastructure; //creates WSADATA struct required for winsock init
    int result;
    struct sockAddr_in clientAddr; //struct required by connect()
    char TXbuffer[500] = "Hell from client";
    char RXbuffer[500];
    result = WSAStartup(MAKEWORD(2,2), &wsastructure); //Initialize winsock
    //WSAStartup args: Winsock version, addr of data structure
    if(result != 0){
        printf("Winsock initialization failed\n");
        return 1;
    }
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    clientAddr.sin_family = AF_INET; //IPv4
    clientAddr.sin_port = htons(9001);
    clientAddr.sin_addr.s_addr = inet_addr("IP_ADDRESS"); //Client IP Address
    
    connect(clientSocket, (SOCKADDR*) &clientAddr, sizeof(clientAddr)) //connect to server
    recv(clientSocket, RXbuffer, sizeof(RXData), 0); //receive server data
    printf("From Server: %s\n, RXbuffer");
    send(clientSocket, TXbuffer, sizeof(TXbuffer), 0); //send data
    closesocket(clientSocket); //close socket connection
    WSACleanup();
    return 0;
}
/*ISM*/
