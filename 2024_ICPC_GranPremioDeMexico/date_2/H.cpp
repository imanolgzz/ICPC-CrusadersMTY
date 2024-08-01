#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
  public:
    Node* l;
    Node* r;
    int val;
    Node(){
      l = nullptr;
      r = nullptr;
      val = 0;
    }
    Node(Node* _l, Node* _r, int _val){
      l = _l;

      val = _val;
    }
    Node(int _val){
      val = _val;
    }
};

int main(){
  int n, r, c;
  cin >> n >> r >> c;
  vector<int>hired;
  Node* previous = new Node(1);
  Node* head = previous;
  for(int i = 2; i <=n; i++){
    Node* next = new Node(i);
    next -> l = previous;
    previous -> r = next;
    previous = next;
  }
  previous -> r = head;
  head -> l = previous;
  Node* rPointer = head;
  Node* cPointer = head -> l;
  while(n > 2){
    // cout << n << " " << rPointer -> val << " " << cPointer -> val << endl;
    int rMod = (r-1) % n;
    int cMod = (c-1) % n;
    // 1 2 3 4 5
    for(int i = 0; i <rMod; i++){
      rPointer = rPointer -> r;
    }
    for(int i = 0; i <cMod;i++){
      cPointer = cPointer -> l;
    }
    if(cPointer -> val == rPointer -> val){
      // cout << "hiring: " << cPointer -> val;
      hired.push_back(cPointer -> val);
      cPointer -> l -> r = cPointer -> r;
      cPointer -> r -> l = cPointer -> l;
      Node*temp = cPointer;
      rPointer = temp -> r;
      cPointer = temp -> l;
      delete(temp);
      n--;
    } else {
      // 1 3 5
      // cout << "deleting: " << cPointer -> val << " and " << rPointer -> val << endl;
      cPointer -> l -> r = cPointer -> r;
      cPointer -> r -> l = cPointer -> l;
      Node*temp = cPointer;
      cPointer = temp->l;
      delete(temp);
      rPointer -> l -> r = rPointer -> r;
      rPointer -> r -> l = rPointer -> l;
      Node*temp2 = rPointer;
      if(rPointer -> val != rPointer -> r -> val){
        rPointer = temp2 -> r;
        delete(temp2);
      }
      n-=2;
    }
  }

  while(n > 0){
    hired.push_back(rPointer -> val);
    rPointer -> l -> r = rPointer -> r;
    rPointer -> r -> l = rPointer -> l;
    Node*temp = rPointer;
    rPointer = temp -> r;
    rPointer = temp -> l;
    delete(temp);
    n--;
  }

  sort(hired.begin(), hired.end());
  for(int item : hired){
    cout << item << " ";
  }
  cout << '\n';
  return 0;

}