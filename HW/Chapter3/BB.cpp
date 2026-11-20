#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct op{
    int aim; // 记录操作的数
    bool action;// 记录入栈(1)还是出栈(0)
};

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>n){
            cout<<"NO";
            return 0;
        }
    }
    
    vector<op>ans;
    stack<int>st;
    int r=1;
    for(int i=0;i<n;i++){
        while(st.empty()||r<arr[i]){// 当前要出栈的数字比已入栈过的数更大，则入栈
            ans.push_back({r,1});
            st.push(r);
            r++;
        }
        if(r==arr[i]){// 当前要出栈的数字恰是下一个要入栈的数字，则先入后出 
            ans.push_back({r,1});
            ans.push_back({r,0});
            r++;
            continue;
        }
        if(r>arr[i]&&st.top()==arr[i]){// 当前要出栈的数字是已入栈过的，只有栈顶=当前出栈数字时成立
            ans.push_back({st.top(),0});
            st.pop();
            continue;
        }

        cout<<"NO";
        return 0;
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i].action){
            cout<<"PUSH "<<ans[i].aim<<endl;
        }
        else{
            cout<<"POP "<<ans[i].aim<<endl;
        }
    }
}