#include <iostream>
#include <vector>
#include "helpers/build_singly_linked_list_from_array.cpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* tail = nullptr;

      while (head) {
        auto c = head->next;

        head->next = tail;
        tail = head;

        head = c;
      }

      return tail;
    }
};

int main() {
  std::vector<int> d1 = {1,2,3,4,5};
  auto l1 = buildList(d1);

  Solution s;
  // auto r1 = l1;
  auto r1 = s.reverseList(l1);

  printList(r1);

  // printList(l1);
}
