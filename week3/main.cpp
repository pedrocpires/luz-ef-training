#include <iostream>
#include <stdlib.h>
#include <string>
// #include <new>

#include "print.h"
#include "allocvector.h"

using namespace std;

struct linked
{
    int n;
    struct linked *next;
};

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

int sizeList(linked *linkedPointer)
{
    if (linkedPointer->n == 0)
    {
        return 0;
    }
    int size = 0;

    linked *list = linkedPointer;

    while (list != NULL)
    {
        list = list->next;

        size++;
    }
    return size;
}

void printList(linked *linkedPointer)
{
    if (sizeList(linkedPointer) == 0)
    {
        cout << "\nA lista está vazia!\n";
    }
    else
    {
        linked *list = linkedPointer;

        cout << "\n | ";
        while (list != NULL)
        {
            cout << list->n << " | ";
            list = list->next;
        }
        cout << "\n";
    }
}

void addBeginning(linked *&linkedPointer, int n)
{
    linked *newValue = new linked;
    newValue->n = n;

    if (sizeList(linkedPointer) == 0)
    {
        newValue->next = NULL;
    }
    else
    {
        newValue->next = linkedPointer;
    }

    linkedPointer = newValue;
}

void addEnd(linked *&linkedPointer, int n)
{

    if (sizeList(linkedPointer) == 0)
    {
        addBeginning(linkedPointer, n);
    }
    else
    {
        linked *newValue = new linked;
        newValue->n = n;
        newValue->next = NULL;

        linked *list = linkedPointer;

        while (list != NULL)
        {
            if (list->next == NULL)
            {
                list->next = newValue;
                return;
            }
            list = list->next;
        }
    }
}

void removeBeginning(linked *&linkedPointer)
{
    if (sizeList(linkedPointer) == 1)
    {
        cout << "\nO valor " << linkedPointer->n << " foi removido do início da lista.\n";

        linked *newValue = new linked;
        newValue->n = 0;
        newValue->next = NULL;

        linkedPointer = newValue;
    }
    else if (sizeList(linkedPointer) == 0)
    {
        cout << "\nNão foi possível remover um valor. A lista está vazia!\n";
    }
    else
    {
        cout << "\nO valor " << linkedPointer->n << " foi removido do início da lista.\n";
        linkedPointer = linkedPointer->next;
    }
}

void removeEnd(linked *&linkedPointer)
{
    if (sizeList(linkedPointer) == 1)
    {
        cout << "\nO valor " << linkedPointer->n << " foi removido do início da lista.\n";

        linked *newValue = new linked;
        newValue->n = 0;
        newValue->next = NULL;

        linkedPointer = newValue;
    }
    else if (sizeList(linkedPointer) == 0)
    {
        cout << "\nNão foi possível remover um valor. A lista está vazia!\n";
    }
    else
    {
        linked *list = new linked;

        list = linkedPointer;

        while (list->next->next != NULL)
        {
            list = list->next;
        }
        cout << "\nO valor " << list->next->n << " foi removido do início da lista.\n";

        list->next == NULL;
    }
}

char menuLinkedList()
{
    linked *linkedPointer = new linked;
    linkedPointer->n = 0;
    linkedPointer->next = NULL;

    while (true)
    {
        char option;
        cout << "\n\n|====================================================|\n";
        cout << "\nEscolha uma operação:\n\n";
        cout << "[ 1 ] Inserir valor no INÍCIO da lista\n";
        cout << "[ 2 ] Inserir valor no FINAL da lista\n";
        // cout << "[ X ] Inserir valor em uma POSIÇÂO QUALQUER da lista\n";
        cout << "[ 3 ] Remover valor no INÍCIO da lista\n";
        cout << "[ 4 ] Remover valor no FINAL da lista\n";
        // cout << "[ X ] Remover valor em uma POSIÇÂO QUALQUER da lista\n";
        cout << "[ 5 ] Quantidade de elementos da lista\n";
        cout << "[ 6 ] Imprimir lista\n";

        cout << "\n[ 0 ] Sair\n\n";
        cout << "|====================================================|\n";

        cin >> option;

        int n;
        switch (option)
        {
        case '1':
            system("clear");
            cout << "\nDigite um número para inserir no início da lista.\n";
            cin >> n;
            addBeginning(linkedPointer, n);
            break;
        case '2':
            system("clear");
            cout << "\nDigite um número para inserir no final da lista.\n";
            cin >> n;
            addEnd(linkedPointer, n);
            break;
        case '3':
            system("clear");
            removeBeginning(linkedPointer);
            break;
        case '4':
            system("clear");
            removeEnd(linkedPointer);
            break;
        case '5':
            system("clear");
            cout << "\nA lista Encadeada tem " << sizeList(linkedPointer) << " elementos.\n";
            break;
        case '6':
            system("clear");
            printList(linkedPointer);
            break;
        case '0':
            exit(0);
        default:
            cout << "\nOpção inválida. Por favor, tente novamente.\n\n";
            break;
        }

        // return option;
    }
}

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