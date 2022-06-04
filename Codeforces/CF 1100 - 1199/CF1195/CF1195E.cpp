#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,a,b,x,y,z,i;
  cin>>n>>m>>a>>b;
  ll g[m-b];
  cin>>g[0]>>x>>y>>z;
  ll ans;
  for (i=1;i<=m-b;i++)
  {
  	g[i] = g[i-1] * x + y;
  	g[i]%=z;
  }
  ans=0;
  for (i=1;i<=m-b+1;i++)
  {
  	ans+=g[i-1]*m-1+(((n-a+1)*(n-a+2))/2);
  }
  cout<<ans;
  return 0;
}