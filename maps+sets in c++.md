# Maps & Sets Cheat Sheet

## Header
```c++
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define nl cout<<endl;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define input(a,n) for(int i=0; i<n; i++){ cin>>a[i]; }
#define print(a,n) for(int i=0; i<n; i++){ cout<<a[i]<<" , "; }
#define loop(a,b) for(int i=a;i<b;i++)
```

## Maps
```c++
void solve(){
    /// declaring the map with key(index) as integer, element as string
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
    
    /// Finding size of map
    int len = m.size();
    
    /// erasing a value
    m.erase(3);
    /// clearing the map
    m.clear();   
}
```


## Sets
```c++
void solve(){
    set<int> val; // defining an empty set
    set<int> val1 = {6, 10, 5, 1}; // defining a set with values
    
    set<char> a;
    //Adding elements
    a.insert('G');
    a.insert('F');
    a.insert('G');   // Adding 'G' twice has no effect on set
    // By default set is sorted in ascending order, so F is output before G
    //to make a set that would be sortedin descending order
    set<int, greater<int> > s1;


    //Methods of printing a set
    for (auto i : a) {
        cout << i << ' ';
    }
    cout<<endl;
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    
    
    
    
    
    set<int, greater<int> > s1;
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);
    s1.insert(50);
    s1.insert(10);
 
    // Using find() to find an element(it returns the iterator pointing to the element)
    if(s1.find(30)==s1.end()){
        cout<<"Nai";
    }else{
        cout<<"Ase";
    }
    
    
 
    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());
    
    // remove all elements up to 30 in s2
    s2.erase(s2.begin(), s2.find(30));
    
    // remove element with value 50 in s2
    s2.erase(50);
    
    
    
    
    
    int arr[] = { 12, 3, 5, 7, 19 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    ///Assigning the array to the set
    set<int> s(arr, arr + N);
 
    // s.begin() returns a pointer to first element in the set
    set<int>::iterator itr = s.begin();
    advance(itr, K - 1);    // itr now points to kth(smallest) element in set
    cout << *itr << "\n";
    
}
```


## Finding frequency of strings using Map
```c++
void findFreqOfStrings(int n, vector<string> s){
    map<string, int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(auto &i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
}
```
## Creating map ussing values in a vector, adding values of map and using reverse iterator
```c++
int mapSum(vector<int> &nums)
{
    map<int, int> mapp;

    for (int i = 0; i < nums.size(); i++)
    {
        mapp[nums[i]]++;
    }
    map<int, int>::reverse_iterator it;
    int sum = 0;
    for (it = mapp.rbegin(); it != mapp.rend(); it++)
    {
        sum += it->second;
    }
    return sum;
}

```
## Main
```c++
int main(){
    solve();
    findFreqOfStrings();
    return 0;
}
```






