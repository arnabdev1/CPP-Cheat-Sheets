# Bit Manipulation Cheat Sheet

## Binary to decimal conversion
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

## Decimal to binary conversion
```c++
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string ans = "";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans+="1";
        else
            ans+="0";
    }
    return ans;
}
```

## 2^n
```c++
int power(int n){
	return(1<<i)
}
```

## Check if bit i is set in n
```c++
bool getBit(int n, int i){
	if(n&(1<<i))            // returns 0 when bit is not set
	    return true;
	else
	    return false;
}
```


## Set (to 1) bit i in n 
```c++
int setBit(int n, int i){
	return (n| 1<<i);
}
```


## Unset (to 0) bit i in n 
```c++
int unsetBit(int n, int i){
	return n & ~(1<<i);
}
```

## Method 1: Check if n is a power of 2
```c++
bool power2(int n){
	if((n&n-1)==0){         // this returns 0 for any power of 2 as they only have 1 set bit
		return true;
	}
	return false;
}
```

## Method 2: Check if n is a power of 2
```c++
bool power2(int n){
	return (n>0 and !(n&(n-1)));
}
```


## Algorithm 1 for counting set Bits
```c++
int countSetBit(int n){
	count=0;
	while(n){
	    n &=(n-1);
	    count++;
	}
	return count;
}
```
## Algorithm 2 for counting set Bits
```c++
int countSetBit(int n){
	count=0;
	while(n){
	    count+=(n&1);
	    n=n>>1;
	}
	return count;
}

```


## All possible subsets of a set(ex- if size or array is 4, this will use all binary characters from 0(0000) to 4^2=16(1111))
```c++
void subsets(int arr[], int n){
	for(int i=0; i<(1<<n); ++i){            // iterating from 1 to n^2(all possible permutations of n digits)
		for(int j=0; j<n; j++){         // iterating for all the n elements of the array
			if(i&(1<<j)){           // checking if bit j is set      
				cout<<arr[j]<<" ";
			}
		}
		cout<<endl;
	}
}
```






## Check if two integers have opposite signs
```c++
if(x^y >0)
    return false;
else
    return true;
```

## Add 1 to a given number
```c++
(-(~x));
```

## Multiply a number by 2
```c++
x<<1;
```

## Divide a number by 2
```c++
x>>1;
```

## Turn off the rightmost set bit
```c++
x&(x-1);
```

## Check whether a given number is a power of 4 or not
```c++
if(!(x & (x-1))){
    if(__builtin_ctz(x)%2==0)
        return true;
```

## Compute modulus division by a power-of-2-number
```c++
x & (powerOf2 - 1);
```

## Rotate bits of a number
```c++
int leftCircularShift(int x,int shiftBy)
    return (x<<shiftBy) | (x>>shiftBy);

int rightCircularShift(int x,int shiftBy)
    return (x>>shiftBy) | (x<<shiftBy);
```

## Count number of bits to be flipped to convert A to B
```c++
__builtin_popcount(a ^ b);
```



## Position of rightmost set bit
```c++
ffs(x);
//another way
log2(x & -x)+1;
//another way
if(x!=0)
    __builtin_ctz(x)+1;
```

## Calculate XOR from 1 to n
```c++
switch(n & 3) // n % 4  
{ 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
} 
```

## Binary representation of a given number
```c++
void bin(unsigned n) 
{ 
    if (n > 1) 
        bin(n>>1); 
      
    cout<<(d & 1)<<endl;
}
```

## Find position of only set bit
```c++
if(!(n&(n-1)))
	ffs(n);
```

## Check if 2 numbers are equal
```c++
if((x ^ y))
    return false;
else
    return true;
```

## Find XOR of numbers without using xor operator
```c++
(x | y) & (~x | ~y);
```

## Swap three variables
```c++
x = x ^ y ^ z;
y = x ^ y ^ z;
z = x ^ y ^ z;
x = x ^ y ^ z;
```

## Toggle Kth bit of a number
```c++
x = x ^ 1<<(k-1);
```

## Toggle all bits except Kth bit of a number
```c++
x = ~(x ^ 1<<(k-1);)
```

## Set the rightmost unset bit
```c++
x = x | (x+1)
```

## Toggle the last m bits
```c++
x ^ ~(-1<<m);
```

## Maximum XOR-value of at-most k-elements from 1 to n
```c++
int x = log2(n) + 1;
return x<<1 - 1;

//Alt way

int res = 1; 
while (res <= n) 
    res <<= 1; 
// Finding number greater than 
// or equal to n with most significant  
// bit same as n. For example, if n is 
// 4, result is 7. If n is 5 or 6, result  
// is 7 
// Return res - 1 which denotes 
// a number with all bits set to 1 
return res - 1; 
``` 

## Check if a number is divisible by 8 using bitwise operators
```c++
return (((n >> 3) << 3) == n);
```

## Toggle bits of a number except first and last bits
```c++
int size = sizeof(int)*8 - __builtin_clz(n);
int one = (1<<(size-1))-1;
n = n ^ one;
n = n ^ 1;
```

# Toggle all even bits of a number
```c++
int temp = n,i=1;
while(temp){
    n = n ^ 1>>(i*2);
    i++;
    temp = temp>>1;
}
```

# Toggle all even bits of a number
```c++/// swap 2 values a and b
a=a^b
b=b^a
a=a^b
```

