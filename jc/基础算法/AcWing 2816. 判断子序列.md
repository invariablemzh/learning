```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);
    for(int i = 0;i<m;i++) scanf("%d",&b[i]);
    bool flag = false;
    for(int i = 0,j = 0;i<m;i++){
        if(j<n&&b[i]==a[j]) j++; 
        if(j==n) {
            flag = true;
            break;
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
```
