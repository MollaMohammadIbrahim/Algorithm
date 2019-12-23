#include<bits/stdc++.h>
using namespace std;
int lps [1000007];
int compare(){}
void kmp(){}
int search(){}

void kmp (string pat , int pat_length){
    
    for( int i =0; i<pat_length+10; i++){
        lps[i]=0;
    }

    lps[0]=0;
    
    int i = 0,j=1;
    while (j<pat_length){
        if(pat[i]==pat[j]){
            lps [j]= i+1;
            i++;
            j++;
        }
        else if(pat[i]!=pat[j]){
            if (i==0){
                lps[j]=0;
                j++;
            }
            else i = lps[i-1];
        }
    }
}

int search(string text, string pat, int text_length,int pat_length){
    int i =0;int j=0;int cnt = 0;
    while(i<text_length){
        if(text[i]==pat[j]){
            i++;j++;
        }

        else{
            if(j==0)i++;
            else j = lps[j-1];
        }

        if(j==pat_length)return 1;
    }
    return 0;
}

int compare(string text ,string pat){
    int text_length, pat_length;
    text_length = text.length();
    pat_length = pat.length();
    
    //To make longest suffix-preffix table
    kmp(pat , pat_length);

    int x = search(text,pat,text_length,pat_length);
    return x;

}
int main(){
    string text,pat;
    cout<<"Enter Test Cases: ";
    int test;
    cin>>test;
    while(test--){
        cout<<"Enter your text Here "<<endl;
        cin>>text;
        cout<<"Enter your pattern here"<<endl;
        cin>>pat;

        if(compare(text,pat)==1)cout<<"FOUND"<<endl;
        else cout<<"NOT_FOUND"<<endl;
    }
 
}