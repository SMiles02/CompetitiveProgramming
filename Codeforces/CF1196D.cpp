#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

string strBuilder(string s0, string s1, string s2, int k)
{
	string s = "";
	for (int i=0;i<k;++i)
	{
		if (i%3==0)
		{
			s.append(s0);
		}
		else if (i%3==1)
		{
			s.append(s1);
		}
		else
		{
			s.append(s2);
		}
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n,k,cur1,cur2,ans;
	string s,s1,s2;
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>n>>k;
		cin>>s;
		s1=strBuilder("R","G","B",k);
		s2=s1;
		s2.erase(0,1);
		if (k%3==0)
		{
			s2.append("R");
		}
		else if (k%3==1)
		{
			s2.append("G");
		}
		else
		{
			s2.append("B");
		}
		//cout<<"s1: "<<s1<<"\n";
		//cout<<"s2: "<<s2<<"\n";
		//cout<<"s3: "<<s3<<"\n";
		ans=k;
		for (int j=0;j<=n-k;j++)
		{
			//cout<<"j= "<<j<<"\n";
			cur1=0;
			cur2=0;
			for (int add=0;add<k;++add)
			{
				if (s1[add]==s[j+add])
				{
					//cout<<"s1 equal!\n";
					++cur2;
				}
				else if (s2[add]==s[j+add])
				{
					//cout<<"s2 equal!\n";
					++cur1;
				}
				else
				{
					//cout<<"s3 equal!\n";
					++cur2;
					++cur1;
				}
			}
			ans=min({ans,cur1,cur2,(2*k)-cur1-cur2});
		}
		cout<<ans<<"\n";
	}
	return 0;
}