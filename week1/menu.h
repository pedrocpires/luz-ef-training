#include <iostream>

#include "allocvector.h"
#include "million.h"

using namespace std;

int size;

char menuSort()
{
    char option;
    cout << "\nEscolha uma opção para ordenação\n\n";
    cout << "[ 1 ] Bubble Sort\n";
    cout << "[ 2 ] Insertion Sort\n";
    cout << "[ 3 ] Selection Sort\n";
    cout << "\n[ 0 ] Sair\n\n";
    cin >> option;
    return option;
}

int *menuInsertVector()
{
    // int size;
    char option;
    int n;

    while (true)
    {
        cout << "\nDigite o tamanho do vetor: (0 para sair)\n";
        cout << "Tamanho: ";
        cin >> size;
        if (size >= 2)
        {
            break;
        }
        else if (size == 0)
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "Opção inválida. Por favor, digite um número maior que 2.";
        }
    }
    int *v;
    v = allocVector(size);

    while (true)
    {
        cout << "\nEscolha uma opção para preencher o vetor\n\n";
        cout << "[ 1 ] Inserir " << size << " números manualmente\n";
        cout << "[ 2 ] Inserir " << size << " números aleatórios\n";
        cout << "\n[ 0 ] Sair\n\n";
        cin >> option;

        if (option == '1')
        {
            for (int i = 0; i < size; i++)
            {
                cout << "\nDigite o " << i + 1 << "° número:";
                cin >> n;
                v[i] = n;
            }
            break;
        }
        else if (option == '2')
        {
            for (int i = 0; i < size; i++)
            {
                v[i] = rand() % 100;
            }
            break;
        }
        else if (option == '2')
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "Opção inválida. Por favor, digite um número maior que 2.";
        }
    }

    return v;
}

int *menuVector()
{
    char option;

    while (true)
    {
        cout << "\nEscolha uma opção para ordenação\n\n";
        cout << "[ 1 ] Inserir vetor manualmente\n";
        cout << "[ 2 ] Ordenar vetor com 10 milhões de registros\n";
        cout << "\n[ 0 ] Sair\n\n";
        cin >> option;
        if (option == '1')
        {
            return menuInsertVector();
            break;
        }
        else if (option == '2')
        {
            return million();
            break;
        }
        else if (option == '0')
        {
            cout << "\nBye!\n\n";
            exit(0);
        }
        else
        {
            cout << "Opção inválida. Por favor, digite um número maior que 2.";
        }
    }
}