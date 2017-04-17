#include<bits/stdc++.h>
using namespace std;

list< list<string> > first_data;

bool str_equal(string a,string b)
{
    return a==b;
}
/*void calculate_first(list<string> grammar,string var,list<string> &temp)
{
    if(!isupper(var[0]))
    {
        temp.push_back(var.substr(0,1));
        return;
    }
    cout<<"var=="<<var;
    list<string>::iterator it=grammar.begin();
    while(it!=grammar.end())
    {
        string g=*it;
        if(g.substr(0,1)==var.substr(0,1))
        {
            string right=g.substr(3); cout<<"right_FIRST=="<<right;
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
}*/


void calculate_first(list<string> grammar,string var,list<string> &temp)
{
    //cout<<"\nvar=="<<var;
    string fc=var.substr(0,1);
    if(!isupper(fc[0]))
           {temp.push_back(fc); /*cout<<"pushing"<<fc<<"\n";*/}

    else
    {
        list<string>::iterator it=grammar.begin();
        while(it!=grammar.end())
        {
           string g=(*it);it++;
           string l=g.substr(0,1);string r=g.substr(3);
           if(l==fc)
           {
               list<string> sub;
               calculate_first(grammar,r,sub); sub.unique();
               list<string>::iterator it1=sub.begin();
               while(it1!=sub.end())
               {
                  if((*it1)=="#")
                  {
                      //cout<<"hash found";
                      if(var.length()>1)
                        {calculate_first(grammar,var.substr(1),temp); /*cout<<"removing hash\n";*/}
                       else temp.push_back("#");
                      break;
                  }
                  else {temp.push_back((*it1)); /*cout<<"pushing"<<(*it1)<<"\n";*/}
                  it1++;
               }

           }


        }
    }
}

void first(list<string> &grammar,list< list<string> > &f)   //this function will contain list of vectors
{
    //cout<<"first\n";
   list<string>::iterator it1=grammar.begin();
   //list<list<string>> f;
   //All the variable are stored in vector variable

   list<string> variable;
   while(it1!=grammar.end())
   {
       string prod=*it1;
       string var=prod.substr(0,1); //cout<<var<<"\t";
       variable.push_back(var);
       for(int i=3;i<prod.length();i++)
       {
         variable.push_back(prod.substr(i,1));
       }
       it1++;
   }
   variable.sort();
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

void calculate_follow(list<string> grammar,string var,list<string> &temp)
{
    if(var.substr(0,1)=="S"||var.substr(0,1)=="E") temp.push_back("$");
    cout<<"\n calculate_folllow of var=="<<var<<"\n";
    list<string>::iterator it1=grammar.begin();
    while(it1!=grammar.end())
         {
        string e=*it1;
        string right=e.substr(3); cout<<"right="<<right<<"\n";
        size_t pos=right.find(var);
        if(pos!=-1) // the variable is present on right hand side
        {

            if(pos==right.length()-1)
            {
                cout<<"equal to length";
                // go to left
                calculate_follow(grammar,(*it1).substr(0,1),temp);
            }
            else
            {
             // check it it tend to #
             // calculate the first and check if it contains #
             string s=right.substr(pos+1);
             list<string> y;
             calculate_first(grammar,s,temp);
             // now y contains the first
             int eps=0;
             list<string>::iterator n=temp.begin();
              // to remove the inital which contain whose first is this
             while(n!=temp.end())
             {
                 if((*n)=="#")
                 {
                     eps=1;
                     break;
                 }
                 n++;
             }
             if(eps==1) // it contains #
                {
                    //cout<<"removing";
                    temp.remove("#");
                    calculate_follow(grammar,(*it1).substr(0,1),temp);
                }

            }


        }
        it1++;
}


list<string>::iterator z=temp.begin();cout<<"\n----------------follow is\n";
while(z!=temp.end())
{
    cout<<*z<<"---------------\n";z++;
}

}

void follow(list<string> grammar)   // this function will return the lost of vectors
{
// hi
}

int main()
{
    list<string> a,b;
    a.push_back("S->ABC");
    a.push_back("A->a");
    a.push_back("A->#");
    a.push_back("B->b");
    a.push_back("B->#");
     a.push_back("C->c");
    a.push_back("C->#");
     cout<<"\n\ncalculating follow";
     calculate_follow(a,"C",b);

    list<string>::iterator it=b.begin();
    cout<<"\n\n";
    while(it!=b.end())
    {
        cout<<*it<<"\n";
        it++;
    }

    /*cout<<"\nhjwkjke\n";
    calculate_first(a,"ABb",b);

    cout<<"----------------------------------";

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


*/}
