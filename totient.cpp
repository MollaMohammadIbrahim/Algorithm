#include<bits/stdc++.h>
#define mx 10000005
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(int i =a;i<b;i++)
void totient(int n);
int phi[mx];
bool mark[mx];

using namespace std;
int main(){
    
    cout<<"Enter N : ";
    int n;
    cin>>n;

    totient(n);

    fr(i,0,n){
        cout<<i<<" "<<phi[i]<<endl;
    }
    return 0;
}
///////////////////////////////////////////////////

void totient(int n){
    fr(i,0,n)phi[i]=i;

    ms(mark,true);

    for(int i=2;i<n;i++){
        if(mark[i]==true){
            for(int j=i;j<n;j+=i){
                mark[j]=false;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}