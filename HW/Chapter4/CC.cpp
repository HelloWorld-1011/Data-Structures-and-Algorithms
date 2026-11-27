#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<string>arr(n);
    for(auto &s:arr)cin>>s;
    string tmp;
    cin>>tmp;

    vector<string>pat;
    for(int i=0;i<tmp.size();i++){
        string st;
        if(tmp[i]=='['){
            while(tmp[++i]!=']')st+=tolower(tmp[i]);
        }
        else{
            st=string(1,tolower(tmp[i]));
        }
        pat.push_back(st);
    }

    for(int i=0;i<n;i++){
        const string &s=arr[i];
        if(s.size()!=pat.size())continue;
        bool ok=true;
        for(int j=0;j<s.size()&&ok;j++){
            if(pat[j].find(tolower(s[j]))==string::npos)ok=false;
        }
        if(ok)cout<<i+1<<" "<<s<<"\n";
    }
}