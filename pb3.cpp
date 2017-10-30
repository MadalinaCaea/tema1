#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

bool compare(const pair<int,int>&i, const pair<int,int>&j){
    return i.first < j.first;  //sortare in functie de extremitatea initiala
}

int main()
{
    ifstream f("date2.in");
    int n;
    vector<pair<int,int> >a(100);
    vector<pair<int,int> >sali[100];

    f>>n;

    for(int i=0; i<n; i++)
    {
        f>>a[i].first;
        f>>a[i].second;
    }


    sort(a.begin(),a.begin()+n,compare);

   int h=0; //nr. de sali alocate
    pair<int,int>  s;
    s=a[0]; //primul interval

    sali[h].push_back(s);
    for (int i=1; i<n; i++)  //iau toate intervalele
	{
		for (int j=0; j <=h; j++)  //vad daca fac parte dintr.o sala deja existenta
		{
			if (a[i].first >=sali[j][sali[j].size()-1].second)
			{
				sali[j].push_back(a[i]);
				break;
			}
			else //creez o noua sala
			{
				h++;
				sali[h].push_back(a[i]);
				break;
			}
		}
	}

    cout<<"Sunt necesare: "<<h+1<<" sali.\n";


    for (int i=0; i<=h; i++)
	{
	    cout<<"Sala "<<i+1<<": ";
            for (int j=0; j<sali[i].size(); j++)
		{
			cout<<sali[i][j].first<< "," <<sali[i][j].second<<"    ";
		}

		cout << endl;
	}






    return 0;
}

