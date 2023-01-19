#include <bits/stdc++.h>
using namespace std;

void print(vector<int> data){
    cout << "Total Elements: " << data.size() << "\n";
    for (int datam:data)
        cout << datam << " ";
    cout << "\n\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /// creating a vector
    ///vector <type> name (elements);
    
    ///vector of size 5 with no elements
//    vector<int> data (5); /// int data[5];
//    print(data);
    

    ///vector of size 5 with all elements equal to 2    
//    vector<int> data(5, 2);
//    print(data);

    ///vector of specified elements and copying a vector    
//    vector<int> data({1, 2, 3, 4, 5}); /// int data[] = {1, 2, 3, 4, 5}
//    vector<int> data = {1, 2, 3, 4, 5}; /// int data[] = {1, 2, 3, 4, 5}
//    print(data);
//    vector<int> data2 = data;
//    print(data2);

    
    /// adding elements
//    vector <int> data = {1,2,3};
//    data.push_back(5);
//    data.push_back(7);
//    data.push_back(9);
//    print(data);



    /// data.begin() points to the first element
    /// data.end() points to the last element
    /// data.insert(a, b) adds element b to position a
    /// data.insert(a, c, b) adds element b to position a, c times
//    vector <int> data = {1,2,3};
//    data.insert( data.begin() , 7);
//    data.insert( data.begin() + 2, 7);
//    data.insert(data.end()-1, 7);
//    data.insert(data.begin(), 2, 7);
//    data.insert(data.begin() + 1, 2, 7);
//    print(data);
    
    
    
     /// sorting a vector
//     vector <int> v = {1,2,3};
//     sort(v.begin(), v.end());
//     sort(v.begin(), v.end(), greater<int>());

    
    
    /// reading data from vector
    /// vector_name.size() gives the size of the vector
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    cout << data[2] << "\n";
//    cout << data.front() << "\n";
//    cout << data.back() << "\n";
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    for (int d:data){
//        cout << d << " ";
//    }
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    int ln = data.size();
//    for (int i=0; i<ln; ++i){
//        cout << data[i] << " ";
//    }
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    int ln = data.size();
//    for (int i=2; i<ln-1; ++i){
//        cout << data[i] << " ";
//    }
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//
//    int *d = data.data();
//    cout << d[2];

    
    
    /// updating values
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    data[2] = 7;
//    cout << data[2] << "\n";
//    print(data);

    
    
    
    /// swapping values using .swap()
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    vector <int> data2 = {6, 9, 8};
//
//    cout << "before swap\n";
//    print(data);
//    print(data2);
//
//    data.swap(data2);
//    cout << "after swap\n";
//    print(data);
//    print(data2);


    
    
    /// deleting elements
//    vector <int> data = {3, 2, 1, 6, 4, 2};
//    cout << "Before delete\n";
//    print(data);
//    data.pop_back();
//    data.clear();
//    data.erase(data.begin()+2, data.begin()+3);
//    data.erase(data.begin()+2, data.end()-2);
//    cout << "After delete\n";
//    print(data);


    return 0;
}
