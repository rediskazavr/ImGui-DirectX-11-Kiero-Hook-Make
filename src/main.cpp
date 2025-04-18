#include <iostream>
#include <Windows.h>

using namespace std;

int InjectDLL(DWORD, char*);
int getDLLpath(char*);
int getPID(int*);
int getProc(HANDLE*, DWORD);

int getDLLpath(char* dll){
    std::cout << "Enter path to dll\n";
}

int main(){
    system("Injector");

    int PID = -1;
    char *dll = new char[255];
}