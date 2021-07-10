#include <iostream>
#include <climits>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
 public:
  // first attempt: hard to follow
  ListNode* mergeTwoListsFirst(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) {
      return (l1 ? l1 : l2);
    }
    
    ListNode* ref = (l1->val <= l2->val) ? l1 : l2;
    ListNode* comp = (ref == l1) ? l2 : l1; // Be careful
    ListNode* temp = nullptr;
    ListNode* head = ref;
    
    while (ref->next && comp) {
      if (comp->val <= ref->next->val) {
        // handle comp list
        temp = comp;
        comp = comp->next;
        // handle ref list
        temp->next = ref->next;
        ref->next = temp; // Be careful, ref->next = temp;
        ref = ref->next;
      } else {
        ref = ref->next;
      }
    }
    
    if (comp) {
      ref->next = comp;
    }
    
    return head;
  }

  // Using dummy node: cleaner
  ListNode* mergeTwoListsDummy(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) { // This is not actually necessary. See the modified solution below.
      return l1 ? l1 : l2;
    }
    ListNode* dummy = new ListNode(INT_MIN);
    ListNode* node = dummy;
    
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        node->next = l1;
        l1 = l1->next;
      } else {
        node->next = l2;
        l2 = l2->next;
      }
      node = node->next;
    }
    
    node->next = l1 ? l1 : l2; // concatenate the remaining nodes
    
    return dummy->next;
  }

  // Even cleaner solution
  ListNode* mergeTwoListsCleaner(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(INT_MIN);
    ListNode* tail = dummy; // change the pointer name to tail: more meaningful
    
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2; // this statement will handle the situation of l1 == nullptr or l2 == nullptr automatically
    
    return dummy->next;
  }
};

void printList(ListNode* node) {
  while (node) {
    cout << node->val << " ";
    node = node->next;
  }
}

int main() {
  ListNode* node3 = new ListNode(4);
  ListNode* node2 = new ListNode(2, node3);
  ListNode* node1 = new ListNode(1, node2);
  
  ListNode* node6 = new ListNode(4);
  ListNode* node5 = new ListNode(3, node6);
  ListNode* node4 = new ListNode(1, node5);

  ListNode* l1 = node1;
  ListNode* l2 = node4;

  Solution sol;

  printList(sol.mergeTwoListsCleaner(l1, l2));

  return 0;
}