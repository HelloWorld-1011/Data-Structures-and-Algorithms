#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    while(N--){
        vector<string>suffix;
        string s;
        cin>>s;
        // 中缀转后缀
        stack<char>ops;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                string num(1,s[i]);
                while(i+1<s.size()&&s[i+1]<='9'&&s[i+1]>='0'){
                    i++;
                    num+=s[i];
                }
                suffix.push_back(num);
            }
            else if(s[i]=='('){
                ops.push(s[i]);
            }
            else if(s[i]==')'){ 
                while(ops.top()!='('){
                    suffix.push_back(string(1,ops.top()));
                    ops.pop();
                }
                ops.pop();
            }
            else{ 
                // 如果栈顶元素优先级大于等于当前要入栈的元素，则出栈,否则直接入栈
                while(!ops.empty()&&((ops.top()=='*'||ops.top()=='/')
                    ||((s[i]=='+'||s[i]=='-')&&(ops.top()=='+'||ops.top()=='-')))){
                        suffix.push_back(string(1,ops.top()));
                        ops.pop();
                    }
                    ops.push(s[i]);
            }
        }
        while(!ops.empty()){// 把剩下的元素全部加入suffix数组
            suffix.push_back(string(1,ops.top()));
            ops.pop();
        }

        // 后缀算结果
        stack<int>st;
        for(int i=0;i<suffix.size();i++){
            if(suffix[i][0]>='0'&&suffix[i][0]<='9'){
                st.push(stoi(suffix[i]));
            }
            else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(suffix[i]=="+"){
                    st.push(op1+op2);
                }
                else if(suffix[i]=="-"){
                    st.push(op1-op2);
                }
                else if(suffix[i]=="*"){
                    st.push(op1*op2);
                }
                else{
                    st.push(op1/op2);
                }
            }
        }

        cout<<st.top()<<endl;
    }
}