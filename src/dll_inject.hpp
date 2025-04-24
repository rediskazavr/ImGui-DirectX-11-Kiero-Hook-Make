#ifndef INJECT_DLL_HPP
#define INJECT_DLL_HPP

#include <windows.h>
#include <iostream>

typedef void (*FP_LoadLibrary)(const char *);

int InjectDLL(DWORD PID, char* dllPath);
int getDLLpath(char* dllPath);
int getPID(int* PID);
int getProc(HANDLE* handleToProc, DWORD pid);
int main_func();

#endif // INJECT_DLL_HPP