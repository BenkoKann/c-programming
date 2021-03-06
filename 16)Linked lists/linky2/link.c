#include<stdio.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

void addLast(node_t * head, int val) {
    node_t * current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

void addFirst(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int removeFirst(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if(*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;
    return retval;

}

int removeLast(node_t * head) {
    int retval = 0;
    if(head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    node_t * current = head;
    while(current->next->next != NULL) {
        current = current-> next;
    }
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

// removes by index

int remove(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if(n == 0) {
        return removeFirst(head);
    }

    for(i = 0; i < n-1; i++) {
        if(current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

int removeFirstOccurence(node_t ** head, int val) {
    node_t * current = *head;
    node_t * temp_node = NULL;

    if(current->val == val) {
        removeFirst(head);
    }
    
    while(current != NULL) {

        if(current->next->val == val) {
            temp_node = current->next;
            current->next = temp_node->next;
            free(temp_node);
            return 1;
        }
        current = current->next;
    }
    return -1;
}

int main() {

    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;

    print_list(head);
    addLast(head, 22);
    addFirst(&head, 111);
    print_list(head);
    removeFirst(&head);
    print_list(head);
    removeLast(head);
    print_list(head);
    addFirst(&head, 0);
    addLast(head, 3);
    addLast(head, 4);
    print_list(head);
    remove(&head, 2);
    print_list(head);
    removeFirstOccurence(&head, 3);
    print_list(head);
    removeFirstOccurence(&head, 0);
    print_list(head);
    // removeFirstOccurence(&head, 1);
    // print_list(head);
    // removeFirstOccurence(&head, 444);
    print_list(head);
    // removeFirstOccurence(&head, 4);
    print_list(head);



    return 0;
}