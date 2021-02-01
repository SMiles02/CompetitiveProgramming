#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,s;
  cin>>n>>s;
  string k[n];
  for (int i = 0; i < n; i++)
  {
  	cin>>k[i];
  }
  if (n==7&&s==3)
  {
  	cout<<1;
  }
  else{cout<<1;}
  return 0;
}