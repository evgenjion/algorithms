// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <unordered_map>
#include <iostream>
#include <vector>

// I know that's bad
#include "helpers/build_singly_linked_list_from_array.cpp"

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      auto lenA = listLen(headA);
      auto lenB = listLen(headB);
      auto a = headA;
      auto b = headB;

      while (lenA > lenB) {
        a = a->next;
        lenA--;
      }

      while (lenB > lenA) {
        b = b->next;
        lenB--;
      }

      while (a != b) {
        if (a != NULL) a = a->next;
        if (b != NULL) b = b-> next;
      }

      return a;
    }

    int listLen (ListNode *head) {
      int len = 0;
      ListNode *p = head;

      while (p != NULL) {
        len++;
        p = p->next;
      }

      return len;
    }

    // ListNode *NOT_WORKING(ListNode *headA, ListNode *headB) {
    //   auto l1 = headA;
    //   auto l2 = headB;

    //   std::unordered_map<ListNode*, bool> m;

    //   while (l1 != NULL || l2 != NULL) {
    //     if (m[l1] == true) {
    //       return l1
    //     } else {
    //       m[l1] = true;
    //     }

    //     if (m[l2] == true) {
    //       l2;
    //     } else {
    //       m[l2] = true;
    //     }

    //     if (l1 != NULL) l1 = l1->next;
    //     if (l2 != NULL) l2 = l2->next;
    //   }

    //   return NULL;
    // }
};

int main () {
  std::vector<int> v1 = {1,2,3,4,5,6,7,8,9,10,11,12,13};
  std::vector<int> v2 = {500,499, 498, 497, 496, 495};

  auto l1 = buildList(v1);
  auto l2 = buildList(v2);
  l2->next->next = l1->next->next->next->next->next;

  std::vector<int> vv1 = {1,9,1,2,4};
  std::vector<int> vv2 = {3};
  auto ll1 = buildList(vv1);
  auto ll2 = buildList(vv2);

  ll2->next = ll1->next->next->next;

  Solution *s = new Solution();

  std::cout << "s->getIntersectionNode(l1,l2): " << s->getIntersectionNode(l1, l2) << std::endl;
  std::cout << "s->getIntersectionNode(ll1,ll2): " << s->getIntersectionNode(ll1,ll2) << std::endl;
}
