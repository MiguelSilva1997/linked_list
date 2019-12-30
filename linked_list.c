#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node * next;
} node_t;

void push(node_t * head, int val);
void print_list(node_t * head);
void unshift(node_t ** head, int val);
void shift(node_t ** head);
void remove_index(node_t ** head, int i);

int main() {
  node_t * head = (node_t *) malloc(sizeof(node_t));;
  head->val = 1;
  head->next = NULL;
  push(head, 2);
  push(head, 3);
  unshift(&head, 4);
  remove_index(&head, 0);
  print_list(head);

  return 0;
}

void push(node_t * head, int val) {
  node_t * current = head;
  if(current->next == NULL){
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
  } else {
    push(current->next, val);
  }
}

void print_list(node_t * head) {
  node_t * current = head;
  if(current->next != NULL) {
    printf("%d\n", current->val);
    print_list(current->next);
  } else {
    printf("%d\n", current->val);
  }
}

void unshift(node_t ** head, int val) {
  node_t * new_node;
  new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

void shift(node_t ** head) {
  *head = (*head)->next;
}

void remove_index(node_t ** head, int i) {
  if(i == 0){
    shift(head);
  }
}
