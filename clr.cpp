#include<bits/stdc++.h>
using namespace std;

list< list<string> > first_data;

bool str_equal(string a,string b)
{
    return a==b;
}



void calculate_first(list<string> grammar,string var,list<string> &temp)
{
    //cout<<"\nvar=="<<var;
    string fc=var.substr(0,1);
    if(!isupper(fc[0]))
           {temp.push_back(fc); }

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
                        {calculate_first(grammar,var.substr(1),temp); }
                       else temp.push_back("#");
                      break;
                  }
                  else {temp.push_back((*it1)); }
                  it1++;
               }

           }


        }
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


void calculate_next_state(list<string> &grammar,list< list<string> >& states,list<string> &visited)
{
   list< list<string> >::iterator it=states.begin();
   while(it!=states.begin())
   {
   list<string> lst=*it;
   string state_no=*(lst.begin());
   list<string>::iterator i=visited.begin();int v=0;
   while(i!=visited.end())
   {
       if((*i)==state_no) // its atready visited
       {
           v=1;break;
       }
       i++;
   }

   if(visited==0) //no we have to expand the given list


   }
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
    string k="abcd|abc";
    size_t p=k.find("|");
    cout<<p;

}
