#include<bits/stdc++.h>
using namespace std;
int subSetSumTable[10000][10000];

void makeTable(int n, int sum, int a[]){
    
    subSetSumTable[0][a[0]]=1;
    subSetSumTable[0][0]=1;

    for(int row =1;row<n;row++){
        for(int column = 0; column<=sum; column++){
            if(column<a[row]){
                subSetSumTable[row][column]=subSetSumTable[row-1][column];
            }
            else {
                subSetSumTable[row][column] = subSetSumTable[row -1][abs(column - a[row])] | subSetSumTable[row-1][column];
            }
        }
    }

}

int main(){
    freopen("output.txt","r",stdin);
    int test;
    cin>>test;
    while(test--){
        int n,sum;
        cin>>n>>sum;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        makeTable(n,sum,a);
//Printing sum table
        for(int k=0;k<=sum;k++)cout<<k<<"  ";
        cout<<endl;
        for(int i =0;i<n;i++){
            for (int j=0;j<=sum;j++){
                cout<<subSetSumTable[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<subSetSumTable[n-1][sum]<<endl;
    }
    return 0;
}
/*
Input
First line of input contains T, the number of test cases. T test cases follow.
Each test case contains 2 lines. First line contains two integers N and K. 
Next line contains N space separated non-negative integers

Output
Output T lines, one for each test case. 
Every line should be either 0 or 1 depending on whether such a subset exists or not.
*/