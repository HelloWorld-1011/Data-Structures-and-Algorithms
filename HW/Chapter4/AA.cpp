#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,t;
    while(cin>>s>>t){
        int s_size=s.size(),t_size=t.size();
        int t_pos=0;
        bool fail=false;
        for(int i=0;i<s_size;i++){
            char curr_ch=s[i];
            while(t_pos<t_size&&t[t_pos]!=curr_ch)
                t_pos++;
            if(t_pos==t_size){
                cout<<"No"<<endl;
                fail=true;
                break;
            }
            t_pos++;
        }
        if(!fail){
            cout<<"Yes"<<endl;
        }
    }
}