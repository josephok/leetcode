// 2. Add Two Numbers
//
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a
// single digit. Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1, *p2, *new_node;
    struct ListNode* p = NULL;
    struct ListNode* cur = NULL;
    struct ListNode* prev = NULL;
    int val, val1, val2;
    // carry
    int carry = 0;
    p1 = l1;
    p2 = l2;

    // checkout which list is longer, if l1, set longer = 1, otherwise 0
    int longer = 1;
    while (p1 || p2) {
        if (p2 == NULL) {
            longer = 1;
            break;
        }
        if (p1 == NULL) {
            longer = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    if (longer == 1) {
        p = l1;
    }
    else {
        p = l2;
    }

    prev = cur = p;
    p1 = l1;
    p2 = l2;
    while (cur) {
        if (p1 == NULL) {
            val1 = 0;
        }
        else {
            val1 = p1->val;
        }
        if (p2 == NULL) {
            val2 = 0;
        }
        else {
            val2 = p2->val;
        }
        val = val1 + val2 + carry;
        if (val >= 10) {
            val %= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        cur->val = val;
        if (cur->next) {
            prev = cur->next;
        }
        cur = cur->next;

        if (p1) {
            p1 = p1->next;
        }
        if (p2) {
            p2 = p2->next;
        }
    }

    if (carry == 1) {
        new_node = malloc(sizeof(struct ListNode));
        new_node->val = 1;
        new_node->next = NULL;
        prev->next = new_node;
    }
    return p;
}

/* Function to create a new node with given data */
struct ListNode *newNode(int val)
{
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node = newNode(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void printList(struct ListNode *node)
{
    while(node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    struct ListNode* res = NULL;
    struct ListNode* first = NULL;
    struct ListNode* second = NULL;

    // create first list 2->4->3
    push(&first, 3);
    push(&first, 4);
    push(&first, 2);
    printf("First List is ");
    printList(first);

    // create second list 5->6->4
    push(&second, 4);
    push(&second, 6);
    push(&second, 5);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoNumbers(first, second);
    printf("Resultant list is ");
    printList(res);

    assert(res->val == 7);
    assert(res->next->val == 0);
    assert(res->next->next->val == 8);
    assert(res->next->next->next == NULL);
    return 0;
}
