```c++
#include <iostream>
using namespace std;
typedef long long ll;

int main(){
	double n; scanf("%lf",&n);
	double l = -10000,r = 10000;
	while(r - l > 1e-9){
		double mid = (l+r)/2;
		if(mid * mid * mid >= n) r = mid;
		else l = mid;
	}
	printf("%lf\n",l);
	return 0;
}
```
