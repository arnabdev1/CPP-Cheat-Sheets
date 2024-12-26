# Graphs Cheat Sheet

## BFS Traversal
```c++
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
