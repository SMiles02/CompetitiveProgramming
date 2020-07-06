#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,d,cur,ans;
  string s;
  cin>>n>>d;
  cin>>s;
  cur=0;
  ans=0;
  while (cur!=n-1)
  {
  	for (int i=min(n-1,cur+d);i>=cur;--i)
  	{
  		if (i==cur)
  		{
  			cout<<-1;
  			return 0;
  		}
  		if (s[i]=='1')
  		{
  			cur=i;
  			++ans;
  			break;
  		}
  	}
  }
  cout<<ans;
  return 0;
}