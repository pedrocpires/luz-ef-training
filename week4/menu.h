#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

char menu()
{
    char option;
    cout << "\nEscolha uma opção:\n\n";
    cout << "[ 1 ] Inserir nó\n";
    cout << "[ 2 ] Remover nó\n";
    cout << "[ 3 ] Buscar nó\n";
    cout << "[ 4 ] Imprimir em ordem\n";
    cout << "[ 5 ] Imprimir em Pré-ordem\n";
    cout << "[ 6 ] Imprimir em Pós-ordem\n";
    cout << "\n[ 0 ] Sair\n\n";
    cin >> option;
    return option;
}
