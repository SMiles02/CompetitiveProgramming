#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,x,y,z,a,b,c,i;
  cin>>n;
  cin>>x>>y>>z;
  for (i=1;i<n;++i)
  {
  	cin>>a>>b>>c;
  	x+=a;
  	y+=b;
  	z+=c;
  }
  //cout<<x<<" "<<y<<" "<<z<<"\n";
  if (x==0&&y==0&&z==0)
  {
  	cout<<"YES";
  }
  else
  {
  	cout<<"NO";
  }
  return 0;
}