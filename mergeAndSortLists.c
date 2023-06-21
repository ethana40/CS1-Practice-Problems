#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// in this problem you will need to write two functions.  
// the mergeSort function sorts the given list of ints in
// ascending order, for example 5->3->7->1 would become 1->3->5->7.
// the mergeTwoLists function takes two sorted lists and merges them
// into a single sorted list.
// Use recursion in both of the functions.

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
    // write your code here
}

// sort the individual lists
Node* mergeSort(Node* list)
{
    // write your code here
}

// add node to list
Node* addNode(Node **list, int data)
{
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

    for (int i = 0; i < list1Length; i++)
    {
        r = rand();
        Node *new = addNode(&list1Head, r);
    }

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

    printf("List 1 post-sort:\n");
    printList(list1Head);
    printf("List 2 post-sort:\n");
    printList(list2Head);

    Node* mergedList = mergeTwoLists(list1Head, list2Head);

    if (isListSorted(mergedList) == 0)
        printf("mergeTwoLists is not working properly.\n");

    printf("Merged list:\n");
    printList(mergedList);


}