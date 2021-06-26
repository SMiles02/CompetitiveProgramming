#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,k;
  cin >> n;
  for (i=0;i<n;i++)
  {
  	cin>>k;
  	cout<<k-(1-(k%2))<<" ";
  }

  return 0;
}