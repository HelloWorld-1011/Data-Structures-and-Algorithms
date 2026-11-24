#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* KMP 算法 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while(cin>>s&&s!="."){
        int n=s.size();
        vector<int>next(n);
        int len=0; // 上一轮算出来的最长公共真前后缀长度

        for(int k=1;k<n;k++){
            while(len>0&&s[k]!=s[len])len=next[len-1];// 如果新字符不匹配，就试试最长前后缀的最长前后缀
            if(s[k]==s[len])len++;
            next[k]=len;
        }

        int p=n-next[n-1];
        cout<<(n%p?1:n/p)<<endl;// 能整除才行
    }
}