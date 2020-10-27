#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void allocVector(int *v, int *size)
{
    v = (int *)malloc((*size) * sizeof(int));
}

void printVector(int *v, int size)
{
    int i;
    cout << " | ";

    for (i = 0; i < size; i++)
    {
        if (v[i] != NULL)
        {
            cout << v[i] << " | ";
        }
        else
        {
            cout << "--"
                 << " | ";
        }
    };
    cout << "\n\n";
}

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
    allocVector(v, size);
}

void menuStack(int *v, int *size)
{
    int top = -1;

    char option;

    while (true)
    {
        cout << "\nEscolha uma opção:\n\n";
        cout << "[ 1 ] Empilhar (push)\n";
        cout << "[ 2 ] Desenpilhar (pop)\n";
        cout << "[ 3 ] Mostrar Topo\n";
        cout << "\n[ 0 ] Sair\n\n";
        cin >> option;

        while (true)
        {
            if (option == '1')
            {
                if (top == *size - 1)
                {
                    cout << "\nA pilha está cheia.\n\n";
                    printVector(v, top + 1);
                    break;
                }
                else
                {
                    int n;
                    top++;
                    cout << "\nDigite o valor:";
                    cin >> n;
                    v[top] = n;
                    printVector(v, top + 1);
                    break;
                }
            }
            else if (option == '2')
            {
                if (top == -1)
                {
                    cout << "\nA pilha está vazia.\n\n";
                    printVector(v, top + 1);
                    break;
                }
                else
                {
                    cout << "\nO valor " << v[top] << " foi desenpilhado!";
                    top--;
                    printVector(v, top + 1);
                    break;
                }
                printVector(v, top);
                break;
            }
            else if (option == '3')
            {
                cout << "\nPosição do topo da pilha: [" << top << "]";
                cout << "\nValor do topo da pilha: | " << v[top] << " |";
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
    }
}

int main()
{
    int size;
    int *v;
    char option;
    while (true)
    {
        option = menu();
        if (option == '1')
        {
            cout << "\nVocê escolheu a estrutura de dados Pilha.\n\n";
            createVector(v, &size);
            menuStack(v, &size);
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