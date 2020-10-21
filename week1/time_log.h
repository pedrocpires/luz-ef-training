#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void time_log(float timer, int size)
{
    ofstream time_log_file;

    time_log_file.open("time_log.txt", std::ios_base::app);

    char log;

    // log = "A ordenação com " + size + " elementos foi executada em " + timer + " milisegundos";
    // log = ;

    time_log_file << "\nA ordenação com " << size << " elementos foi executada em " << timer << "ms";

    time_log_file.close();
}
