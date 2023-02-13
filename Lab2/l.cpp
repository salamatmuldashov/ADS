# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	int mx = -2147483647;
    int max_sum = 0;
    while (head != NULL)
    {
        max_sum = max_sum + head->val;
        if (mx < max_sum)
        {
            mx = max_sum;
        }
        if (max_sum < 0)
        {
            max_sum = 0;
        }
        
        
        head = head->next;
    }
    return mx;
    
 
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}