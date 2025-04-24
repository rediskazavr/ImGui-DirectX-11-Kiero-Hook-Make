#include <iostream>
#include <Windows.h>

using namespace std;

int InjectDLL(DWORD, char*);
int getDLLpath(char*);
int getPID(int*);
int getProc(HANDLE*, DWORD);

int getDLLpath(char* dll){
    std::cout << "Enter path to dll\n";
    cin >> dll;
    return 1;

}

int getPID(int* PID){
    cout << "Enter path PID to your target process\n";
    cin >> *PID;
    return 1;
}

int getProc(HANDLE* handleToProc, DWORD pid){
    *handleToProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
    DWORD dwLastError = GetLastError();

    if(*handleToProc = NULL){
        std::cout << "Undable to open process\n";
        return -1;
    }
    else{
        std::cout << "Process Opened\n";
        return 1;
    }
}

int InjectDLL(DWORD PID, char* dll){
    HANDLE handleToProc;
    LPVOID LoadLibAddr;
    LPVOID baseAddr;
    HANDLE remThread;

    // GET DLL LENGHT
    int dllLenght = strlen(dll) + 1;

    // HOOK PROCESSING PROCESS
    if(getProc(&handleToProc, PID)< 0)
        return -1;

    // LOAD KERNEL32 LIB
    LoadLibAddr = ((LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibAddr"));

    if(!LoadLibAddr)
        return -1;

    baseAddr = VirtualAllocEx(handleToProc, NULL, dllLenght, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if(!baseAddr)
        return -1;

    // WRITE PATH TO DLL
    if(!WriteProcessMemory(handleToProc, baseAddr, dll, dllLenght, NULL))
        return -1;

    // CREATE REMOTE THREAD
    remThread = CreateRemoteThread(handleToProc, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibAddr, baseAddr, 0, NULL);

    if(!remThread)
        return -1;

    WaitForSingleObject(remThread, INFINITE);

    VirtualFreeEx(handleToProc, baseAddr, dllLenght, MEM_RELEASE);

    // CLOSE HANDLER
    if(CloseHandle(remThread) == 0){
        std::cout << "Failed to close handle to remote thread";
        return -1;
    }

    if(CloseHandle(handleToProc) == 0)
    {
        std::cout << "Failed to close handle to target process\n";
    }
}

int main_func(){
    int PID = -1;
    char *dll = new char[255];

    getDLLpath(dll);
    getPID(&PID);

    InjectDLL(PID, dll);
    system("pause");

    return 0;
}