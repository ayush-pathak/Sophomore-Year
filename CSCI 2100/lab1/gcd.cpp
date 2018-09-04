#include <iostream>
using namespace std;

int gcd(int u, int v) {
  /* We will use Euclid's algorithm
     for computing the GCD */
  int r;
  while (v != 0) {
    r = u % v;   // compute remainder
    u = v;
    v = r;
  }
  return u;
}

int main() {
  int a, b;
  cout << "First value: ";
  cin >> a;
  cout << "Second value: ";
  cin >> b;
  cout << "gcd: " << gcd(a,b) << endl;
  return 0;
}
