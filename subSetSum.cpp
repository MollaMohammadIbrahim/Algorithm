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