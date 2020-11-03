#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#include "menu.h"

int main()
{
    int size;
    char option;
    while (true)
    {
        option = menu();
        if (option == '1')
        {
            cout << "\nVocê escolheu a estrutura de dados Pilha.\n\n";
            // createVector(v, &size);
            // menuStack(v, &size);
            break;
        }
        else if (option == '2')
        {
            cout << "\nVocê escolheu a estrutura de dados Fila.\n\n";
            break;
        }
        else if (option == '3')
        {
            cout << "\nVocê escolheu a estrutura de dados Lista Encadeada.\n\n";
            menuLinkedList();
            break;
        }
        else if (option == '0')
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "\nOpção inválida. Por favor, tente novamente.\n\n";
        }
    }

    return 0;
}