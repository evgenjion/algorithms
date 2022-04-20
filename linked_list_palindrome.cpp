// https://leetcode.com/problems/palindrome-linked-list/
#include "helpers/build_singly_linked_list_from_array.cpp"

#include <vector>
#include <iostream>

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
    bool isPalindrome(ListNode* head) {
      return slowFast(head);
      // return vectorSolution(head);
    }

    // O(N) space, O(N^2) time
    bool vectorSolution(ListNode* head) {
      std::vector<int> v {};

      if (head == nullptr) return true;

      while (head != nullptr) {
        v.push_back(head->val);
        head = head->next;
      }

      for (int i = 0; i < v.size()/2; i++) {
        if (v[i] != v[v.size() - i - 1]) {
          return false;
        }
      }

      return true;
    }

    // O(1) space, O(N) time
    bool slowFast(ListNode *head) {
      ListNode* slow;
      ListNode* fast;

      slow = fast = head;

      if (head == nullptr || head->next == nullptr) return true;

      while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
      }

      auto r = reverseList(slow->next);
      slow = r;

      while (slow != nullptr) {
        if (slow->val != head->val) {
          return false;
        }

        slow = slow->next;
        head = head->next;
      }

      return true;
    }

    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return head;
      if (head->next == nullptr) return head;

      ListNode* tail = nullptr;

      while (head != nullptr) {
        auto n = head->next;
        head->next = tail;
        tail = head;
        head = n;
      }

      return tail;
    }
};

int main() {
  std::vector<int> vp = {1,2,2,1};
  std::vector<int> v = {1,2,3};

  Solution s;

  auto lp = buildList(vp);
  auto l = buildList(v);

  std::cout << "s.isPalindrome(lp) [1]: " << s.isPalindrome(lp) << std::endl;
  std::cout << "s.isPalindrome(l) [0]: " << s.isPalindrome(l) << std::endl;

  // auto t = s.reverseList(l);

  // printList(t);
}
