#include "testlib.h"
 
using namespace std;
 
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
 
    int t = inf.readInt(1, 1e5, "t");
    inf.readEoln();
    
    int sum_n = 0;
    for (int test = 0; test < t; test++)
    {
        int n = inf.readInt(1, 2e5, "n");
        sum_n += n;
        ensuref(sum_n <= 2e5, "Sum n too big");
        inf.readEoln();
        for (int i = 0; i < n; i++)
        {
            int u = inf.readInt(-1e9, 1e9, "a_i");
            if (i + 1 < n)
                inf.readSpace();
            else
                inf.readEoln();
        }
    }
    inf.readEof();
}