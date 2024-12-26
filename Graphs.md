# Graphs Cheat Sheet

## BFS Traversal
![image](https://github.com/user-attachments/assets/1eb8e9d5-2e81-40d3-a8fa-e0671f2ada98)
```c++
// 0 has no neighbors(DNE), 1's neighbors are 2 and 6 and so on.
adj[][] = {{},{2,6},{1,3,4},{2},{2,5},{4,8},{1,7,9}}
int binaryToDecimal(int n)
{
    int dec_num = 0 ;
    int power = 0 ;
    while(n>0){
      if(n%10 == 1){ // extracting the last digit
        dec_num += (1<<power) ;
      }
      power++ ;
      n = n / 10 ;
    }
      return dec_num ;
}
```
