#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        int n=s.size();
        string sstr=s.substr(n-3,3);
        string str=s.substr(0,n-4);

        int max_pos=0;
        char max_ele=str[0];
        for(int i=1;i<str.size();i++){
            if(str[i]>max_ele){
                max_ele=str[i];
                max_pos=i;
            }
        }

        cout<<str.substr(0,max_pos+1)+sstr+str.substr(max_pos+1,str.size()-max_pos-1)<<endl;
    }
}