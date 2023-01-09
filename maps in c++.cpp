#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define nl cout<<endl;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define input(a,n) for(int i=0; i<n; i++){ cin>>a[i]; }
#define print(a,n) for(int i=0; i<n; i++){ cout<<a[i]<<" , "; }
#define loop(a,b) for(int i=a;i<b;i++)
void findFreqOfStrings(){
    int n;
    cin>>n;
    string s;
    map<string, int> m;
    for(int i=0;i<n;i++){
        cin>>s;
        auto it = m.find(s);
        if(it == m.end()){
            m[s]=1;
        }else{
            m[s]++;
        }
    }
    for(auto &i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
}

void solve(){
    /// declaring the map with key as integer, element as string
    map<int, string> m;
    m[1] = "abc";
    m[5] = "acc";
    m[3] = "abb";
    m.insert({7,"afg"});
    /// printing the map where .first returns the key and .second returns the element
    
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    /// checking if a key exists in the map
    auto it = m.find(3);
    if(it == m.end()){
        no;
    }else{
        yes;
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    /// erasing a value
    m.erase(3);
    /// clearing the map
    m.clear();
    
    
    
    
}
int main(){
    solve();
    findFreqOfStrings();
    return 0;
}
