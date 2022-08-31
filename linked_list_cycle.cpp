// Да, знаю, что плохо
#include "helpers/build_singly_linked_list_from_array.cpp"

#include <vector>
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (head == NULL) return false;
      auto p1 = head;

      while (head->next != NULL) {
        head = head->next;
        p1 = p1->next;

        if (p1 == NULL || p1->next == NULL) {
          return false;
        }

        p1 = p1->next;

        if (head == p1) {
          return true;
        }
      }

      return false;
    }
};

int main() {
  Solution s;

  std::vector<int> v = {1,2,3,4,5,6};

  auto head = buildList(v);

  head->next->next->next->next = head->next->next;

  std::cout << "s.hasCycle(head): " << s.hasCycle(head) << std::endl;
}
