#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
 	ios_base::sync_with_stdio(0); cin.tie(0);
	std::ifstream in("mixin.txt");
    std::ofstream out("mixout.txt");
    int n,d,a,b;
    in >> n >> d;
    b = n%d;
    a = n/d;
    if (b == 0)
    {
        out << a;
    }
    else
    {
        out << a << " " << b << "/" << d;
    }
 	return 0;
}