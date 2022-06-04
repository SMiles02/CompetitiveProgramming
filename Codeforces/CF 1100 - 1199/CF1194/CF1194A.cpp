#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t,n,x;
  cin>>t;
  for (int i = 0; i < t; i++)
  {
  	cin>>n>>x;
  	cout<<2*x<<"\n";
  }
  return 0;
}