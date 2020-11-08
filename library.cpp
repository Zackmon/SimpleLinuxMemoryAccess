#include "library.h"


void PrintHelloWorld() {
    std::cout << "Hello, World!" << std::endl;
}

void freeingMemory (char* memoryAddress){
    free (memoryAddress);
}

unsigned char* ReadMemory(int pid, char* address, int maxLength){

    size_t bufferLength = maxLength;

    struct iovec local[1];
    local[0].iov_base = calloc(bufferLength,sizeof(char ));
    local[0].iov_len = bufferLength;

    struct iovec remote[1];
    remote[0].iov_base = address;
    remote[0].iov_len = bufferLength;

    ssize_t nread = process_vm_readv(pid, local, 2, remote, 1, 0);
    if (nread < 0) {
        switch (errno) {
            case EINVAL:
                printf("ERROR: INVALID ARGUMENTS.\n");
                break;
            case EFAULT:
                printf("ERROR: UNABLE TO ACCESS TARGET MEMORY ADDRESS.\n");
                break;
            case ENOMEM:
                printf("ERROR: UNABLE TO ALLOCATE MEMORY.\n");
                break;
            case EPERM:
                printf("ERROR: INSUFFICIENT PRIVILEGES TO TARGET PROCESS.\n");
                break;
            case ESRCH:
                printf("ERROR: PROCESS DOES NOT EXIST.\n");
                break;
            default:
                printf("ERROR: AN UNKNOWN ERROR HAS OCCURRED.\n");
        }

        return reinterpret_cast<unsigned char *>(-1);
    }

    unsigned char * finalValue = static_cast<unsigned char *>(local[0].iov_base);

    return finalValue;
}



void WriteMemory (int pid , char* address, unsigned char* value, int valueSize){
    size_t bufferLength = valueSize;

    struct iovec local[1];
    local[0].iov_base = value;
    local[0].iov_len = bufferLength;

    struct iovec remote[1];
    remote[0].iov_base = address;
    remote[0].iov_len = bufferLength;

    ssize_t nread = process_vm_writev(pid, local, 2, remote, 1, 0);
    if (nread < 0) {
        switch (errno) {
            case EINVAL:
                printf("ERROR: INVALID ARGUMENTS.\n");
                break;
            case EFAULT:
                printf("ERROR: UNABLE TO ACCESS TARGET MEMORY ADDRESS.\n");
                break;
            case ENOMEM:
                printf("ERROR: UNABLE TO ALLOCATE MEMORY.\n");
                break;
            case EPERM:
                printf("ERROR: INSUFFICIENT PRIVILEGES TO TARGET PROCESS.\n");
                break;
            case ESRCH:
                printf("ERROR: PROCESS DOES NOT EXIST.\n");
                break;
            default:
                printf("ERROR: AN UNKNOWN ERROR HAS OCCURRED.\n");
        }


    }




}





