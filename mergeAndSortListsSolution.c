#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// node definition
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *list1Head = NULL;
Node *list2Head = NULL;

// merge the two lists
Node* mergeTwoLists(Node* list1, Node* list2)
{
    // create a new list called result to merge the two lists into
    Node* result = NULL;

    // Base case: If either list is null, return the other list
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    
    // recursive call to merge the lists
    if (list1->data <= list2->data)
    {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }
    return result;
}

// sort the individual lists
Node* mergeSort(Node* head)
{
    // Base case: If the list is empty or has only one node, return the list
    if (head == NULL || head->next == NULL)
        return head;

    // Split the list into two halves
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = NULL;

    // Recursively sort the two halves
    Node* sortedFirstHalf = mergeSort(head);
    Node* sortedSecondHalf = mergeSort(secondHalf);

    // Merge the sorted halves
    return mergeTwoLists(sortedFirstHalf, sortedSecondHalf);
}

// add node to list
Node* addNode(Node **list, int data)
{
    printf("addNode called, inserting %d\n", data);
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;

    new->data = data;
    new->next = *list;
    *list = new;

    return new;
}

// print the list
void printList(Node *list)
{
    Node *current = list;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
    return;
}

int isListSorted(Node* head)
{
    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        // check if the current element is greater than the next element
        if (current->data > current->next->data)
            return 0; // list is not sorted properly

        current = current->next;
    }

    return 1; // list is sorted properly
}

int main(int argc, char* argv)
{
    srand(time(NULL));
    int list1Length, list2Length, r;

    list1Length = rand() % 20;
    list2Length = rand() % 20;

    printf("List 1 inserts: \n");
    for (int i = 0; i < list1Length; i++)
    {
        r = rand();
        Node *new = addNode(&list1Head, r);
    }

    printf("List 2 inserts: \n");
    for (int i = 0; i < list2Length; i++)
    {
        r = rand();
        Node *new = addNode(&list2Head, r);
    }

    printf("List 1 pre-sort:\n");
    printList(list1Head);
    printf("List 2 pre-sort:\n");
    printList(list2Head);

    list1Head = mergeSort(list1Head);
    list2Head = mergeSort(list2Head);
    
    if ((isListSorted(list1Head) == 0) || (isListSorted(list2Head) == 0))
        printf("mergeSort is not working properly.\n");

    printf("List 1:\n");
    printList(list1Head);
    printf("List 2:\n");
    printList(list2Head);

    Node* mergedList = mergeTwoLists(list1Head, list2Head);

    if (isListSorted(mergedList) == 0)
        printf("mergeTwoLists is not working properly.\n");

    printf("Merged list:\n");
    printList(mergedList);


}