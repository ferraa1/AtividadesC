#include "main.h"
#define SIZE 1000000
int * dados = NULL;

// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "VIRUS", MB_OK | MB_ICONINFORMATION);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            if (dados == NULL) {
                dados = new int [SIZE];
                int a;
                for (a = 0; a < SIZE; a++) {
                    dados[a] = a;
                }
            }
            cout << "DLL carregada!" << endl;
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            delete dados;
            cout << "DLL liberada!" << endl;
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
