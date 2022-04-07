```c++
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5+10;

int n,m;
int a[N];
int s[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
        s[i] = a[i] - a[i-1];
    }
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        s[l] += c;
        s[r+1] -= c;
    }
    for(int i = 1;i<=n;i++){
        s[i] += s[i-1];
        printf("%d ",s[i]);
    }
    return 0;
}
```
