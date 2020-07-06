#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
bool rankings(int n, int d, int finalRank, int s[], int p[])
{
	int score = s[d-1] + p[0];
	int adder = n-1;
	for (int i = finalRank-1; i < d-1; i++)
	{
		if (s[i] + p[adder] > score)
		{
			return false;
		}
		adder--;
	}
	return true;
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,d,i;
  cin>>n>>d;
  int s[n];
  int p[n];
  for (i=0;i<n;i++)
  {
  	cin>>s[i];
  }
  for (i=0;i<n;i++)
  {
  	cin>>p[i];
  }
  for (i=1;i<d;i++)
  {
  	if (rankings(n,d,i,s,p))
  	{
  		break;
  	}
  }
  cout<<i;
  return 0;
}