#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    int a = 5;
    printf("%d", a);
}