```
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5+10, M = 1<<20;
typedef long long ll;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;
struct Range{
    int l,r;
    bool operator<(const Range &W)const{
        return l<W.l;
    }
}range[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        range[i] = {l,r};
    }
    sort(range,range+n);
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i = 0;i<n;i++){
        if(heap.empty()||range[i].l<=heap.top()) {
            heap.push(range[i].r);
        }
        else{
            heap.pop();
            heap.push(range[i].r);
        }
    }
    printf("%d\n",heap.size());
}
```
