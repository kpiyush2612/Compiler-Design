#include<bits/stdc++.h>
using namespace std;


void calculate_first(list<string> grammar,string var,list<string> &temp)
{
    list<string>::iterator it=grammar.begin();
    while(it!=grammar.end())
    {
        string g=*it;
        if(g.substr(0,1)==var)
        {
            string right=g.substr(3);
            if(!isupper(right.substr(0,1)[0]))
            {
                temp.push_back(right.substr(0,1));
            }
            else
			{
				if(right.length()==1)
				{
					list<string>::iterator it1=grammar.begin();
					int present=0;
					while(it1!=grammar.end())
					{
						string f=right.substr(0,1)+"->#";
						if(*it1==f)
						{present=1;break;}
					    it1++;
					}
					if(present==0)
						calculate_first(grammar,right,temp);		
				}
				
				else
				{
					calculate_first(grammar,right.substr(0,1),temp);
					temp.remove("#");
					calculate_first(grammar,right.substr(1),temp);
					
				}

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
    list<string> a,b;
    a.push_back("S->Da");
    a.push_back("D->b");
	a.push_back("D->#");
    calculate_first(a,"s",b);
    list<string>::iterator i=b.begin();
    while(i!=b.end())
    {
    	cout<<*i<<"\t";
    	i++;
    }
}
