```c++
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010;
int q[N],tmp[N];

ll merge_sort(int l,int r){
	if(l>=r) return 0;
	ll mid = l+r>>1, i = l, j = mid + 1, k = 0;
	ll res = merge_sort(l,mid)+merge_sort(mid+1,r);
	while(i<=mid&&j<=r){
		if(q[i]<=q[j]) tmp[k++] = q[i++];
		else{
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while(i<=mid) tmp[k++] = q[i++];
	while(j<=r) tmp[k++] = q[j++];
	for(i = 0,j = l;i<k;i++) q[j++] = tmp[i];
	return res;
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&q[i]);
	printf("%lld",merge_sort(1,n));
	return 0;
}
```
