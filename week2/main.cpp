#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <time.h>

#include "menu.h"
#include "sort.h"
#include "print.h"

using namespace std;

// Função principal, executa ao iniciar o programa.
int main()
{
    char option;

    while (true)
    {
        int *vector;
        int size;
        option = menuSort();
        if (option == '1')
        {
            cout << "\nVocê escolheu a opção Quick Sort para ordernar.\n\n";
            menuVector(&vector, &size);
            int timer;
            clock_t t_start, t_end;
            t_start = clock();

            quickSort(vector, 0, size);

            t_end = clock();
            timer = difftime(t_end, t_start);
            time_log(timer, size);

            printVector(vector, size);
            break;
        }
        else if (option == '2')
        {
            cout << "\nVocê escolheu a opção Merge Sort para ordernar.\n\n";
            menuVector(&vector, &size);

            int timer;
            clock_t t_start, t_end;
            t_start = clock();

            mergeSort(vector, 0, size);

            t_end = clock();
            timer = difftime(t_end, t_start);
            time_log(timer, size);

            printVector(vector, size);
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
