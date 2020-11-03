#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// #include "linkedFunctions.h"
#include "print.h"

char menu()
{
    char option;
    cout << "\nEscolha uma opção:\n\n";
    cout << "[ 1 ] Estrutura de dados Pilha\n";
    cout << "[ 2 ] Estrutura de dados Fila\n";
    cout << "[ 3 ] Estrutura de dados Lista Encadeada\n";
    cout << "\n[ 0 ] Sair\n\n";
    cin >> option;
    return option;
}

void menuStack(int *v, int *size)
{
    //     int top = -1;

    //     char option;

    //     while (true)
    //     {
    //         cout << "\nEscolha uma opção:\n\n";
    //         cout << "[ 1 ] Empilhar (push)\n";
    //         cout << "[ 2 ] Desenpilhar (pop)\n";
    //         cout << "[ 3 ] Mostrar Topo\n";
    //         cout << "\n[ 0 ] Sair\n\n";
    //         cin >> option;

    //         while (true)
    //         {
    //             if (option == '1')
    //             {
    //                 if (top == *size - 1)
    //                 {
    //                     cout << "\nA pilha está cheia.\n\n";
    //                     printVector(v, top + 1);
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     int n;
    //                     top++;
    //                     cout << "\nDigite o valor:";
    //                     cin >> n;
    //                     v[top] = n;
    //                     printVector(v, top + 1);
    //                     break;
    //                 }
    //             }
    //             else if (option == '2')
    //             {
    //                 if (top == -1)
    //                 {
    //                     cout << "\nA pilha está vazia.\n\n";
    //                     printVector(v, top + 1);
    //                     break;
    //                 }
    //                 else
    //                 {
    //                     cout << "\nO valor " << v[top] << " foi desenpilhado!";
    //                     top--;
    //                     printVector(v, top + 1);
    //                     break;
    //                 }
    //                 printVector(v, top);
    //                 break;
    //             }
    //             else if (option == '3')
    //             {
    //                 cout << "\nPosição do topo da pilha: [" << top << "]";
    //                 cout << "\nValor do topo da pilha: | " << v[top] << " |";
    //             }
    //             else if (option == '0')
    //             {
    //                 cout << "\nBye!\n\n";
    //                 exit(0);
    //             }
    //             else
    //             {
    //                 cout << "\nOpção inválida. Por favor, tente novamente.\n\n";
    //             }
    //         }
    //     }
}

char menuLinkedList()
{
    linked *linkedPointer = new linked;
    linkedPointer = NULL;

    lists *firstList = new lists;
    firstList->name = 'First';
    firstList->size = 0;
    firstList->start = NULL;
    firstList->end = NULL;

    system("clear");

    cout << "\n\n";

    while (true)
    {
        char option;
        cout << "\n\n|====================================================|\n";
        cout << "\nEscolha uma operação:\n\n";
        cout << "[ 1 ] Inserir valor no INÍCIO da lista\n";
        cout << "[ 2 ] Inserir valor no FINAL da lista\n";
        cout << "[ 3 ] Remover valor no INÍCIO da lista\n";
        cout << "[ 4 ] Remover valor no FINAL da lista\n";
        cout << "[ 5 ] Quantidade de elementos da lista\n";
        // cout << "[ 6 ] Imprimir lista\n";

        cout << "\n[ 0 ] Sair\n\n";
        cout << "|====================================================|\n";

        cin >> option;

        int n;
        switch (option)
        {
        case '1':
            system("clear");
            cout << "\nDigite um número para inserir no início da lista.\n\n";
            cin >> n;
            addBeginning(&firstList, n);
            system("clear");
            printList(&firstList);
            break;
        case '2':
            system("clear");
            cout << "\nDigite um número para inserir no final da lista.\n\n";
            cin >> n;
            addEnd(&firstList, n);
            system("clear");
            printList(&firstList);
            break;
        case '3':
            system("clear");
            removeBeginning(&linkedPointer, &firstList);
            system("clear");
            printList(&firstList);
            break;
        case '4':
            system("clear");
            removeEnd(&linkedPointer, &firstList);
            system("clear");
            printList(&firstList);
            break;
        case '5':
            system("clear");
            cout << "\nA lista Encadeada tem " << sizeList(&firstList) << " elementos.";
            break;
        case '6':
            system("clear");
            printList(&firstList);
            break;
        case '0':
            exit(0);
        default:
            cout << "\nOpção inválida. Por favor, tente novamente.\n\n";
            break;
        }
    }
}