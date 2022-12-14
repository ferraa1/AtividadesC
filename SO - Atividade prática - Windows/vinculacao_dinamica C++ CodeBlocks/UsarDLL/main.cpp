#include <iostream>
#include <windows.h>
using namespace std;
typedef void(WINAPI* dllF) (LPCSTR);
int main() {
    string linha;
    cout << "Aperte Enter para carregar DLL" << endl;
    getline(cin, linha);
    HINSTANCE dll = LoadLibrary("MinhaDLL.dll");
    if (dll != NULL) {
        cout << "Aperte Enter para buscar a fun��o" << endl;
        getline(cin, linha);
        dllF func = (dllF)GetProcAddress(dll, "SomeFunction");
        if (func != NULL) {
            cout << "Fun��o SomeFunction encontrada!" << endl;
            func("Ah ah ah! You didn't say the magic word!");
        } else {
            cout << "Erro ao procurar a fun��o" << endl;
        }
    } else {
        cout << "N�o foi poss�vel carregar a DLL" << endl;
    }
    cout << "Aperte Enter fechar a biblioteca" << endl;
    getline(cin, linha);
    FreeLibrary(dll);
    cout << "Aperte Enter para sair" << endl;
    getline(cin, linha);
    return 0;
}
