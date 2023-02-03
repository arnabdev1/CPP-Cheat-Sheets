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
