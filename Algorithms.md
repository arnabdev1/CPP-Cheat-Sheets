# Common algorithms cheat sheet



## Binary Search Iterative
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
```
## Binary Search Recursive
```c++
class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target){
        if (l > r) return -1;
        int m = l + (r - l) / 2;
        
        if (nums[m] == target) return m;
        return ((nums[m] < target) ? 
                binary_search(m + 1, r, nums, target) : 
                binary_search(l, m - 1, nums, target));
    }

    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }
};
```
## Binary Search with built-in functions
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
    }
};
```



## Find target or largest element smaller than target
```
## Binary Search with built-in functions
```c++
class Solution {
public:
    int searchOrFloor(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                ans = m;       // potential floor
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans; // index of floor or -1 if no floor exists
    }
};

```



## Find target or smallest element larger than target
```
## Binary Search with built-in functions
```c++
class Solution {
public:
    int searchOrCeil(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                ans = m;       // potential ceil
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans; // index of ceil or -1 if no ceil exists
    }
};
```
