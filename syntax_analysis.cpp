#include<bits/stdc++.h>
using namespace std;


void calculate_first(list<string> grammar,string var,vector<string> &temp)
{
    list<string>::iterator it=grammar.begin();
    while(it!=grammar.end())
    {
        string g=*it;
        if(g.substr(0,1)==var)
        {
            string right=g.substr(3);
            if(islower(right.substr(0,1)[0]))
            {
                temp.push_back(right.substr(0,1));
            }


        }
        it++;
    }
}

void first(list<string> &grammar)   //this function will contain list of vectors
{


   list<string>::iterator it1=grammar.begin();

   //All the variable are stored in vector variable

   vector<string> variable;
   while(it1!=grammar.end())
   {
       string prod=*it1;
       string var=prod.substr(0,1); cout<<var<<"\t";
       variable.push_back(var);
       it1++;
   }

   // for each character in vector find its first and store it in list of vector




}

void follow(list<string> grammar)   // this function will return the lost of vectors
{
   //cout
}

int main()
{
    list<string> a;
    a.push_back("A->a");
    a.push_back("B->b");
    calculate_first(a,"A");
}

