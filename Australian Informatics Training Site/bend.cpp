#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
 	ios_base::sync_with_stdio(0); cin.tie(0);
	std::ifstream in("bendin.txt");
    std::ofstream out("bendout.txt");
    int x1,y1,x2,y2,i1,j1,i2,j2,shared;
    in >> x1 >> y1 >> x2 >> y2;
    in >> i1 >> j1 >> i2 >> j2;
    if ((x1 <= i1 && i1 <= x2) && (y1 <= j1 && j1 <= y2))
    {
        shared = (x2-i1)*(y2-j1);
    }
    else if ((x1 <= i2 && i2 <= x2) && (y1 <= j2 && j2 <= y2))
    {
        shared = (i2-x1)*(j2-y1);
    }
    else
    {
        shared = 0;
    }
    out << ((x2-x1)*(y2-y1))+((j2-j1)*(i2-i1))-shared;
 	return 0;
}