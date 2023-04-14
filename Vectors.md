# Vectors Cheat Sheet

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
## Creating, adding elements and copying a Vector
```c++
void (){
   ///vector <type> name (elements);
   ///vector of size 5 with no elements
   vector<int> data (5); /// equivalent of this in an array is int data[5];
   ///vector of size 5 with all elements equal to 2    
   vector<int> data1(5, 2);
   ///vector of specified elements    
   vector<int> data2({1, 2, 3, 4, 5}); /// equivalent of this in an array is int data[] = {1, 2, 3, 4, 5}
   vector<int> data3 = {1, 2, 3, 4, 5}; /// equivalent of this in an array is int data[] = {1, 2, 3, 4, 5}
   ///copying a vector
   vector<int> data4 = data;
}
```



## Multidimensional vectors
```c++
void (){
   ///vector <vector<type1>> name (number of rows,vector<type1>(number of columns, element of type1));
   ///vector with 5 rows, 6 columns in each row containing the string "Arnab"
   vector<vector<string>> data (5,vector<string>(6,"Arnab")); 
   
   //// or
   vector<vector<int>> vv={{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
}
```



## Finding length of a vector
```c++
   vector <int> data = {1,2,3};
   int n= data.size()
```


## Printing the Vector
```c++
void print(vector<int> data){
    cout << "Total Elements: " << data.size() << "\n";
    for (int it:data)
        cout << it << " ";
    cout << "\n\n";
}
```



## Inserting elements, updating elements, indices and pointing to elements(.begin(), .end(), .insert())
```c++
void solve(){
   /// adding elements
   vector <int> data = {1,2,3};
   data.push_back(5);
   data.push_back(7);
   data.push_back(9);
   /// data.begin() points to the first element
   /// data.insert(a, b) adds element b to position a
   /// data.insert(a, c, b) adds element b to position a, c times
   data.insert( data.begin() , 7);
   data.insert( data.begin() + 2, 7);
   /// data.end() points to the last element
   data.insert(data.end()-1, 7);
   data.insert(data.begin(), 2, 7);
   data.insert(data.begin() + 1, 2, 7); 
    
    
   /// updating values and accessing values using index
   vector <int> data1 = {3, 2, 1, 6, 4, 2};
   data1[2] = 7;
   cout << data1[2] << "\n";
}
```


## Sorting a Vector
```c++
void solve(){
    vector <int> v = {1,2,3};
    sort(v.begin(), v.end());  ///Ascending
    sort(v.begin(), v.end(), greater<int>()); ///Descending  
}
```



## (Pairs in vectors)Storing the original indices of a list and then sorting the list in order of element
```c++

    int v[7] = {6,77,8,3,5,2,1};
    vector<pair<int,int>>res;   //// <element,index>
    for(int i=0;i<=6;i++){
         res.push_back({v[i],i});
    }
    
    for(int i=0;i<7;i++) cout<<res[i].first<<" "<<res[i].second<<endl;
    cout<<endl;
    sort(res.begin(),res.end());
    for(int i=0;i<7;i++) cout<<res[i].first<<" "<<res[i].second<<endl;
    

```





## Swapping, clearing and, erasing
```c++
void solve(){
    /// swapping values using .swap()
   vector <int> data = {3, 2, 1, 6, 4, 2};
   vector <int> data2 = {6, 9, 8};
   data.swap(data2);   /// all values get swapped
    
   /// deleting elements
   data.pop_back();   /// remove an element from the back
   data.clear();      ///  used to remove all the elements
   
   /// vector_name.erase(position);    for deletion at specific position
   /// vector_name.erase(starting_position, ending_position);   for deletion in range
   data.erase(data.begin()+2, data.begin()+3); /// deletes elements number 3 to 4
   data.erase(data.begin()+2, data.end()-2);   /// deletes element number 3 to 3rd last(last 2 elements stay)
}
```

## Different ways of reading from a vector
```c++
void solve(){
   vector <int> data = {3, 2, 1, 6, 4, 2};
   cout << data[2] << "\n";
   cout << data.front() << "\n";   /// first element
   cout << data.back() << "\n";    /// last element
   /// printing every element 
   for (int d:data){
       cout << d << " ";
   }
   /// Or
   int ln = data.size();
   for (int i=0; i<ln; ++i){
       cout << data[i] << " ";
   }    
}
```


## Main
```c++
int main(){
    solve();
    return 0;
}
```
