#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,l;
  cin>>n>>m;
  int a[n];
  int dp[n];
  set<int> s;
  for (int i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  for (int i=n-1;i>-1;--i)
  {
  	s.insert(a[i]);
  	dp[i]=s.size();
  }
  for (int i=0;i<m;++i)
  {
  	cin>>l;
  	cout<<dp[l-1]<<"\n";
  }
  return 0;
}