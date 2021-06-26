#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }
int lcm(int a, int b) { return a*(b/gcd(a,b))}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  return 0;
}