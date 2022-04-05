// https://leetcode.com/problems/merge-two-sorted-lists/submissions/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *r = new ListNode(); // "dummy" node
        auto s = r;

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                r->next = list1;
                list1 = list1->next;
            } else {
                r->next = list2;
                list2 = list2->next;
            }

            r = r->next;
        }

        if (list1 == nullptr)
            r->next = list2;

        if (list2 == nullptr)
            r->next = list1;

        return s->next;
    }
};
