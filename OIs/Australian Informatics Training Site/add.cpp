#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    std::ifstream in("addin.txt");
    std::ofstream out("addout.txt");
    int a,b;
    in >> a >> b;
    out << a+b;
    return 0;
}
