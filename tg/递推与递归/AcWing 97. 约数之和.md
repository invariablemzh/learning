1. 时间复杂度：O(2logN)
2. 分治:快排,归并排序
3. 约数之和公式： A = p1^c1 * p2^c2 * ... *pk^ck
4. 约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
5. 约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
6. A^B = p1^(c1*b1) * p2^(c2*b2) * ... *pk^(ck*bk)
7. p^0 + p^1 + ... + p^k = (p^k-1)/(p-1) = sum(p,k)

8. k是偶数
   sum(p,k) = p^0 + p^1 + ... + p^(k/2-1) + p^(k/2)+ ... + p^(k-1)
   			= sum(p,k/2) + p^(k/2) * sum(p,k/2)
   			= (1+p^(k/2))*sum(p,k/2)

9. k是奇数
   sum(p,k) = p^0 + p^1 + ... + p^(k-1)
   			= p^(k-1) + p^0 + p^1 + ... + p^(k-2)
   			= p^(k-1) + sum(p,k-1)
        
```c++
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
const int N = 10, M = 1<<20;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 9901;

int qmi(int a,int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int sum(int p,int k){
    if(k==1) return 1;
    if(k%2==0) return (1+qmi(p,k/2))*sum(p,k/2) % mod;
    return (qmi(p,k-1)+sum(p,k-1)) % mod;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int res = 1;
    for(int i = 2;i<=a/i;i++){
        if(a%i==0){
            int s = 0;
            while(a%i==0){
                a/=i;
                s++;
            }
            res = res * sum(i,b*s+1) % mod;
        }
    }
    if(a>1) res = res * sum(a,b+1) % mod;
    if(a==0) res = 0;
    printf("%d\n",res);
}
```
