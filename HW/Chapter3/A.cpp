#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// 单调双端队列（仅包含求区间最小）

int main()
{
    int n;
    int k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>min;
    deque<int>min_dq;
    for(int i=0;i<n;i++){
        while(!min_dq.empty()&&min_dq.back()<=i-k)min_dq.pop_back();// 移动窗口
        while(!min_dq.empty()&&nums[min_dq.front()]>=nums[i]){// 构造单调递减队列
            min_dq.pop_front();
        }
        min_dq.push_front(i);

        if(i>=k-1)min.push_back(nums[min_dq.back()]);
    }

    for(int i=0;i<min.size();i++)
        cout<<min[i]<<" ";
}
