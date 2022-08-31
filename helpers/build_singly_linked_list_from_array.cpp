#include "linked_list.cpp"

#include <vector>

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

// void printList (ListNode *head) {
//   std::cout << "{ ";

//   while (head) {
//     std::cout << head->val;

//     if (head->next) std::cout << ",";
//     std::cout << " ";

//     head = head->next;
//   }

//   std:: cout << "}" << std::endl;
// }
