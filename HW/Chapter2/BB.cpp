#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

vector<int>trans(string s){
    vector<int>ans;
    istringstream iss(s);
    string token;
    int i=0;
    while(iss>>token){
        if(i%2==1&&stoi(token)<0){
            ans.pop_back();
            return ans;
        }
        ans.push_back(stoi(token));
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        vector<int>poly1=trans(s1);
        vector<int>poly2=trans(s2);
        map<int,int,greater<int>>mp;

        for(int i=0;i<poly1.size();i+=2){
            if(poly1[i+1]>=0){
            mp[poly1[i+1]]+=poly1[i];
            }
        }
        for(int i=0;i<poly2.size();i+=2){
            if(poly2[i+1]>=0){
            mp[poly2[i+1]]+=poly2[i];
            }
        }

        for(auto x:mp){
            if(x.second!=0){
                cout<<"[ "<<x.second<<" "<<x.first<<" ] ";
            }
        }
        cout<<endl;
    }
}