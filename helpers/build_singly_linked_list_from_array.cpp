#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList (std::vector<int> &list) {
  if (!list.size()) return NULL;

  ListNode *head = new ListNode(list[0]);
  auto cur = head;

  for (int i = 1; i < list.size(); i++) {
    ListNode *node = new ListNode(list[i]);
    cur->next = node;

    cur = node;
  }

  return head;
}
