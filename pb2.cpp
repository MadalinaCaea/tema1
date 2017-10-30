#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<set>

using namespace std;

  ifstream  f("date3.in");
   int n, x,y,viz[100], tata[100];
   set<int> final;
   list<int>  la[100];
    vector<int> d;

void dfs1(int s)
{
	viz[s]=1;
	list<int> ::iterator i;
	for(i=la[s].begin(); i!=la[s].end(); i++)
		if(viz[*i]==0)
		{
			tata[*i]=s;
			dfs1(*i);
		}
		d.push_back(s);
}


void dfs(int n)
{
	for (int i=1; i<=n; i++)
	{
		if (viz[i]== 0)
		{
			dfs1(i);
		}
	}

}
int main()
{

   f>>n;
   while(f>>x>>y)
   {
       la[x].push_back(y);
       la[y].push_back(x);
	}

	dfs(n);
	for (int i=0; i<d.size(); i++)
	{
		if (viz[d[i]] == 1)
		{
			final.insert(d[i]);
			viz[tata[d[i]]] = 0;
		}
	}

	cout << final.size() << endl;

	set<int>::iterator i;
	for (i = final.begin(); i != final.end(); i++)
	{
		cout << (*i) << " ";
	}

	cout << endl;
   return 0;
}
