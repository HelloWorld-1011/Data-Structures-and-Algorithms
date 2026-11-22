#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int n=2*N-1;
    vector<vector<int>>arr(n,vector<int>(n,0));
    arr[0][N-1]=1;
    int col=N-1,row=0;
    for(int i=2;i<=n*n;i++){
        if((row==0&&col==n-1)||(row>0&&col<n-1&&arr[row-1][col+1]!=0)){
            row+=1;
            arr[row][col]=i;
            continue;
        }

        if(row==0){
            col+=1;
            row=n-1;
            arr[row][col]=i;
            continue;
        }

        if(col==n-1){
            col=0;
            row--;
            arr[row][col]=i;
            continue;
        }

        col+=1;
        row-=1;
        arr[row][col]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}