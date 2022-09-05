// https://leetcode.com/problems/add-two-numbers/

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

#include <iostream>
#include <vector>
#include <cmath>

#include "./helpers/build_singly_linked_list_from_array.cpp"
#include "./helpers/pretty_print.cpp"

class FallingByAddressSanitizerSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      std::vector<int> v1;
      std::vector<int> v2;
      ListNode* head = new ListNode(0);
      auto cur = head;
      int n1 = 0;
      int n2 = 0;

      while (l1 != nullptr) {
        v1.push_back((l1->val));
        l1 = l1->next;
      }

      while (l2 != nullptr) {
        v2.push_back((l2->val));
        l2 = l2->next;
      }

      for (int i = v1.size(); i--;) { // TODO: same for v2
        short pow = i;// v1.size() - i - 1; // for [9] its 1 - 0 - 1 = 0. // 9 * 2^0
        n1 += v1[i] * std::pow(10, pow);
      }

      for (int j = v1.size(); j--;) { // TODO: same for v2
        short pow = j;// v1.size() - j - 1; // for [9] its 1 - 0 - 1 = 0. // 9 * 2^0
        n2 += v2[j] * std::pow(10, pow);
      }

      // 123
      auto sum = n1 + n2;

      while (sum > 0) {
        auto rest = sum % 10;

        cur->val = rest;

        sum -= rest;
        if (sum > 9) {
          sum /= 10;
          cur->next = new ListNode(0);
          cur = cur->next;
        }
      }

      // TODO: build list from n1
      return head;
    }
};

int main() {
  std::vector<int> v1 = {2, 4, 3};
  std::vector<int> v2 = {5, 6, 4};
  auto l1 = buildList(v1);
  auto l2 = buildList(v2);

  (new Solution())->addTwoNumbers(l1, l2);

  std::vector<int> vv1 = {9,9,9,9,9,9,9};
  std::vector<int> vv2 = {9,9,9,9};
  auto ll1 = buildList((vv1));
  auto ll2 = buildList((vv2));

  // (new Solution())->addTwoNumbers(ll1, ll2);
}
