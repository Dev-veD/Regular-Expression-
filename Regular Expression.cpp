#include<bits/stdc++.h>
using namespace std;
string tst;                     //Test String For Checking If Program Is Correct
vector <int >vec;                  //vector used so as to store base address of pattern found
int r_len(string ptr){          //Returns Expected Length Of String As per Algorithm
int px=0;
for(unsigned int i=0;i<ptr.length();i++){
    if(ptr[i]=='/')
        i=i+1;
    px++;
}
return px;
}
bool is_alpha(char x){          //Check For Alphabet
return((x>=65&&x<91)||(x>=97&&x<123));
}
bool is_int(char x){            //Check For Integer
return (x>=48&&x<59);
}
int get_pttrn(string ptrn){         //Pattern Comparing Function
    int len_r=r_len(ptrn);
for(unsigned int i=0;i<=tst.length()-len_r;i++){
    bool flag =true;
    int k=0;
    for(unsigned int j=0;j<ptrn.length();j++){
        string cmp;
        cmp=ptrn[j];
        if(cmp[0]=='/')
            {cmp=cmp+ptrn[j+1];
            j=j+1;
            }
        if(cmp[1]=='c'&&!is_alpha(tst[k+i]))
        {   flag=false;break;}
        else if(cmp[1]=='d'&&!is_int(tst[k+i]))
        {   flag=false;break;}
        else if(cmp[1]!='c'&&cmp[1]!='d'&&cmp[0]!=tst[k+i])
        {   flag=false;break;}
        k++;
    }

    if(flag==true)
        vec.push_back(i);
}
return 0;
}
int test(){                         //Function Taking Input Of Test String
cout<<"\nEnter the test data :\n";
fflush(stdin);
getline(cin,tst);
return 0;
}
int main()
{
    cout<<"NOTE : If You Have Forward Slashes In Pattern String Just Enter One Extra '/' at the End.\n";
    cout <<"NOTE : Yes I know We Can Use Regular Expression's Pre-implementation but Bare with me You'll Love This.\n\nInput '/c' for Alphabets, '/d' for integers.\n";
    cout<<"You can use Constant Characters if they do-not change in the test string.\nEnter The Pattern :\n";
    string pttrn;
    fflush(stdin);
    getline(cin,pttrn);
    test();

    get_pttrn(pttrn);
    cout<<"Number Of patterns found are :\n";
    cout<<vec.size()<<endl;
    for (unsigned int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" : ";
        for(int j=vec[i];j<r_len(pttrn)+vec[i];j++)
            cout<<tst[j];
        cout<<endl;
    }
    return 0;
}
//Divyanshu Joshi
//Regular Expression Implementation Where The Algorithm Looks For Pattern Given.
//This Is Inspired From Pythons Implementation Of regex.
//Had No Idea That It Was Also Available in C++.
//Making It More general would be a coding challenge but as always challenge accepted.
