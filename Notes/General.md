# **Notes CrusadersMTY ICPC**

**Fast I/O and reading input from files:**

```c++
void setIO() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

int main(){
  ios::sync_with_stdio(false); // disable synchronization between C and C++ std streams
  cin.tie(nullptr); // don´t use this on interactive problems
  cout << flush; // force display in console
  setIO(); // comment this line when uploading code
}
```
