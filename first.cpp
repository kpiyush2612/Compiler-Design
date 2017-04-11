#include<bits/stdc++.h>
using namespace std;



bool str_equal(string a,string b)
{
    return a==b;
}
void calculate_first(list<string> grammar,string var,list<string> &temp)
{
    if(islower(var[0]))
    {
        temp.push_back(var.substr(0,1));
        return;
    }
    cout<<"var=="<<var;
    list<string>::iterator it=grammar.begin();
    while(it!=grammar.end())
    {
        string g=*it;
        if(g.substr(0,1)==var)
        {
            string right=g.substr(3); cout<<"right=="<<right;
            if(!isupper(right.substr(0,1)[0]))
            {
                cout<<"\npushing"<<right.substr(0,1)<<"\n";
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
void first(list<string> &grammar,list< list<string> > &f)   //this function will contain list of vectors
{
   list<string>::iterator it1=grammar.begin();
   //list<list<string>> f;
   //All the variable are stored in vector variable

   list<string> variable;
   while(it1!=grammar.end())
   {
       string prod=*it1;
       string var=prod.substr(0,1); cout<<var<<"\t";
       variable.push_back(var);
       it1++;
   }

   variable.unique(str_equal);
   list<string>::iterator it2=variable.begin();
   while(it2!=variable.end())
   {
       list<string> temp;
       temp.push_back(*it2); // beginning of list contains whose follow is this
       calculate_first(grammar,*it2,temp);
       f.push_back(temp);
       it2++;

   }

}

void follow(list<string> grammar)   // this function will return the lost of vectors
{
   //cout
}

int main()
{
    list<string> a,b;
    a.push_back("S->aABb");
    a.push_back("A->a");
    a.push_back("A->#");
    a.push_back("B->b");
    a.push_back("B->#");


    //calculate_first(a,"b",b);
    list<string>::iterator i=b.begin();
    while(i!=b.end())
    {
    	cout<<*i<<" ";
    	i++;
    }

    list< list<string> > first_data;
    first(a,first_data);
    list< list<string> >::iterator j=first_data.begin();
    while(j!=first_data.end())
    {
        cout<<"\n";
        list<string>::iterator k=(*j).begin();
        while(k!=(*j).end())
        {
            cout<<*k;
            k++;
        }
        j++;
    }


}
