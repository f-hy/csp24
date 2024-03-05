#include<bits/stdc++.h>
using namespace std;
typedef int (*FUNC)(int, int);
class calc {
private:
  static int _add(int x, int y){return x+y;}
  static int sub(int x, int y){return x-y;}
  static int mul(int x, int y){return x*y;}
  static int div(int x, int y){return x/y;}
public:
  static int add(int x,int y){return _add(x,y);}
  static int calculate(int x, int y, FUNC f) {
    return f(x, y);
  }
};
int main() {
  cout<<calc::calculate(3,5,calc::add)<<endl;
  return 0;
}