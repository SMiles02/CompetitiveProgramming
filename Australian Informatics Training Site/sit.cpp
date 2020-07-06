#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
 	ios_base::sync_with_stdio(0); cin.tie(0);
	std::ifstream in("sitin.txt");
    std::ofstream out("sitout.txt");
    int r,s,n;
    in >> r >> s;
    in >> n;
    if (r*s < n)
    {
    	out << r*s << " " << (n-(r*s));
    }
    else
    {
    	out << n << " 0";
    }
 	return 0;
}