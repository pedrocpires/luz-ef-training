#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void time_log(int timer, int size)
{
    ofstream time_log_file;

    time_log_file.open("time_log.txt", std::ios_base::app);

    char log;

    time_log_file << "\nA ordenação com " << size << " elementos foi executada em " << timer << "ms";

    time_log_file.close();
}
