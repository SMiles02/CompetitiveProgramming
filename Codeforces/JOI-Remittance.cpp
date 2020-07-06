#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isDone(int n,int houses[][2])
{
	for (int i = 0; i < n; i++)
	{
		if (houses[i][0]!=houses[i][1])
		{
			return true;
		}
	}
	return false;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,changesMade,removed;
  cin>>n;
  int ab[n][2];
  for (i=0;i<n;i++)
  {
  	cin>>ab[i][0]>>ab[i][1];
  }
  while (isDone(n,ab))
  {
  	changesMade=0;
  	for (i=0;i<n-1;i++)
  	{
  		if (ab[i][0] - ab[i][1] > 1)
  		{
  			cout<<i+1<<"\n";
  			changesMade++;
  			if ((ab[i][0] - ab[i][1]) % 2 == 0)
  			{
  				removed = (ab[i][0] - ab[i][1])/2;
  				ab[i][0] = ab[i][1];
  				ab[i+1][0]+=removed; 
  			}
  			else
  			{
  				removed = (ab[i][0] - ab[i][1] - 1)/2;
  				ab[i][0] = ab[i][1] + 1;
  				ab[i+1][0]+=removed; 
  			}
  		}
  	}
  	if (ab[n-1][0] - ab[n-1][1] > 1)
  	{
  		cout<<n<<"\n";
  		changesMade++;
  		if ((ab[n-1][0] - ab[n-1][1]) % 2 == 0)
  		{
  			removed = (ab[n-1][0] - ab[n-1][1])/2;
  			ab[n-1][0] = ab[n-1][1];
  			ab[0][0]+=removed; 
		}
  		else
  		{
  			removed = (ab[n-1][0] - ab[n-1][1] - 1)/2;
  			ab[n-1][0] = ab[n-1][1] + 1;
  			ab[0][0]+=removed; 
  		}
  	}
  	if (changesMade == 0)
  	{
  		cout<<"No";
  		return 0;
  	}
  }
  cout<<"Yes";
  return 0;
}
//fails 8, 24, 29, 32