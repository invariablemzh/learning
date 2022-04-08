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
const int N = 5e4+10, M = 1<<20;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

stack<int> num;
stack<char> op;

string str;

void eval(){
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();
    int x;
    if(c=='+') x = a + b;
    else if(c=='-') x = a - b;
    else if(c=='*') x = a * b;
    else x = a / b;
    num.push(x);
}

int main(){
    unordered_map<char,int> pr = {{'+',1},{'-',1},{'*',2},{'/',2}};
    cin>>str;
    for(int i = 0;i<str.size();i++){
        char c = str[i];
        if(isdigit(c)){
            int j = i, s = 0;
            while(j<str.size()&&isdigit(str[j]))
                s = 10 * s + (str[j++] - '0');
            i = j - 1;
            num.push(s);
        }
        else if(c=='(') op.push(c);
        else if(c==')'){
            while(op.top()!='(') eval();
            op.pop();
        }
        else{
            while(op.size()&&pr[c]<=pr[op.top()]) eval();
            op.push(c);
        }
    }
    while(op.size()) eval();
    cout<<num.top()<<endl;
}
```
