#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    int n, v[100], s1=0, s2=0, poz=0, poz2=0;
    char a1[100], a2[100]; //vectorul alegerilor
	srand(time(NULL));

    ifstream f("date.in");
    f>>n;
    for(int i=0; i<n; i++)
        f>>v[i];

   int s=0, d=n-1; //extremitatile
    while (s<d)  //cat timp nu am ajuns la mijloc
    {

        if(v[s]==v[d]) //caz1: extremitatile sunt egale
        {
            if(v[s+1]<v[d-1])//aleg stanga
               {
                s1+= v[s];
                a1[poz]='S';
                poz++;
                s++;
               }

            else
                if(v[s+1]>= v[d-1])
            {
                s1+= v[d];
                a1[poz]='D';
                poz++;
                d--;
            }

        }

        else
            if( v[s]> v[d])
        {
                if(v[s+1]> v[s] && v[s+1]>v[d] && v[s+1]>v[d-1] && v[s]>v[d-1])
                     {
                s1+= v[d];
                a1[poz]='D';
                poz++;
                d--;
                    }
                else
                     {
                s1+= v[s];
                a1[poz]='S';
                poz++;
                s++;
                    }

        }

        else
        {

            if (v[d - 1]> v[d] && v[d - 1]> v[s] && v[d - 1]> v[s + 1] && v[s + 1]< v[d])
                {
                s1+= v[s];
                a1[poz]='S';
                poz++;
                s++;
                }

            else
                  {
                s1+= v[d];
                a1[poz]='D';
                poz++;
                d--;
                    }

        }

     int t= rand()% 2;
     if(t==1)
        {
        s2+= v[d];
        a2[poz2]='D';
        poz2++;
        d--;
        }

     else
       if(t==0)
          {
        s2+= v[s];
        a2[poz2]='S';
        poz2++;
        s++;
        }

    }


    if(s1>s2)
        cout<<"Jucatorul 1 a castigat.";
    else
        cout<<"Jucatorul 2 a castigat.";

    cout<<"\n\nSuma obtinuta de primul jucator este: "; cout<<s1;
    cout<<"\nSuma obtinuta de al doilea jucator este: "; cout<<s2;

    cout<<"\n\nMutarile primului jucator sunt: ";
    for(int i=0; i<poz; i++)
        cout<<a1[i];


    cout<<"\n\nMutarile primului jucator sunt: ";
    for(int i=0; i<poz2; i++)
        cout<<a2[i];
    return 0;
}
