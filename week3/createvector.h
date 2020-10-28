#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void createVector(int *v, int *size)
{
    char option;
    int n;

    while (true)
    {
        cout << "\nDigite o tamanho do vetor: (0 para sair)\n";
        cout << "Tamanho: ";
        cin >> *size;
        if (*size >= 2 && *size <= 10000000)
        {
            break;
        }
        else if (*size == 0)
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "Opção inválida. Por favor, digite um valor entre 2 e 10 milhões.";
        }
    }
    // allocVector(v, size);
}