#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
float distance(int x1, int y1, int x2, int y2)
{
	float n = (x2-x1)*(x2-x1);
	float m = (y2-y1)*(y2-y1);
	n+=m;
	return (sqrtf(n));
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  float a,b,n,x,y,v,mini;
  cin>>a>>b;
  cin>>n;
  mini=2000000000;
  for (int i=0;i<n;i++)
  {
  	cin>>x>>y>>v;
  	mini=min(mini,distance(a,b,x,y)/v);
  }
  cout<<setprecision(7)<<mini;
  return 0;
}