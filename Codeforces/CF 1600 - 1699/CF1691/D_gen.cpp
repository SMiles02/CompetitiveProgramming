#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int t = atoi(argv[1]), n, l = atoi(argv[4]), r = atoi(argv[5]);
    cout << t << endl;
    while (t--) {
        n = rnd.next(atoi(argv[2]), atoi(argv[3]));
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            cout << rnd.next(l, r);
            if (i == n)
                cout << "\n";
            else
                cout << " ";
        }
    }
}