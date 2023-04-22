# Combinatronics Cheat Sheet

### 
nPn = n! (permutation of n things in n positions)
nPr = n!/(n-r)!    (permutation of n things in r positions)
nCr = n!/((n-r)!*r*)



## n!
```c++
///EASIER CODE
int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}



///VERY EFFICIENT CODE
unordered_map<ll,ll> m;
ll fact(ll n)
{
    if(n==1 || n==0){
        return 1;
    }
    if(m.find(n)!=m.end()){
        return m[n];
    }
    return m[n]=n * fact(n-1);
}

```

## nCr and nPr(needs fact() function)
```c++
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

///Or
int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}


int nPr(int n, int r)
{
    return fact(n)/fact(n-r);
}
```
