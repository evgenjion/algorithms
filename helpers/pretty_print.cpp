#include <vector>
#include <algorithm>
#include <iterator>

#include "linked_list.cpp"
#include "build_singly_linked_list_from_array.cpp"

template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec)
{
    os<<"{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, ", "));
    os<<"}";

    return os;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, ListNode* head)
{
    os<<"{ ";
    while (head) {
        os << head->val;

        if (head->next) os << ",";
        os << " ";

        head = head->next;
    }
    os<<"}";

    return os;
}
