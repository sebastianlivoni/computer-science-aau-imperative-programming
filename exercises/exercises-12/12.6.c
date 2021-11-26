/*
 * Title: Funktioner på cirkulære lister
 * Description: 
 * Assignment: Opgave 12.6 
 * Inspiration: https://www.geeksforgeeks.org/circular-singly-linked-list-insertion/
 * Link to assignment: http://people.cs.aau.dk/~normark/impr-c/structures-flere-opgaver-slide-exercise-2.html
 * 
 * Programmer: Sebastian Livoni Larsen
 * Date completed: November 26, 2021
 * Instructor: Kurt Nørmark * Class: AAL E21
 */ 

#include <stdio.h>
#include <stdlib.h>

struct point {int x; int y;};
typedef struct point point;

struct list_node {
  void             *data;
  struct list_node *next;
};
typedef struct list_node list_node;

void print_point(point *p);
void print_circular_point_list(list_node *cl);
list_node *insert_head(list_node *last_node, void *el);
list_node *insert_tail(list_node *last_node, void *el);
list_node *delete_head(list_node *last_node);
list_node *delete_tail(list_node *last_node);
int length_of_circular_list(list_node *cl);
list_node *find_previous_node(list_node *cl);
list_node *check_null(list_node *cl, void *el);
list_node *add_to_empty(list_node *last_node, void *el);
void assert_allocation_success(list_node *ln);

int main(void) {
  point p1 = {1,2}, p2 = {3,4}, p3 = {5,6}, p4 = {7,8};

  list_node *circular_list = NULL;

  circular_list = insert_head(circular_list, &p1);
  circular_list = insert_head(circular_list, &p2);
  circular_list = insert_head(circular_list, &p3);
  circular_list = insert_head(circular_list, &p4);

  circular_list = insert_tail(circular_list, &p2);

  circular_list = delete_head(circular_list);
  circular_list = delete_tail(circular_list);
  circular_list = insert_tail(circular_list, &p4);
  circular_list = delete_tail(circular_list);

  printf("Length of circular list: %d\n", length_of_circular_list(circular_list));
  printf("Printing list:\n");
  print_circular_point_list(circular_list);

  return EXIT_SUCCESS;
}

void print_point(point *p){
  printf("(%1d, %1d)\n", p->x, p->y);
}

void print_circular_point_list(list_node *cl){
  list_node *cur, *prev;

  if (cl != NULL) {
   cur = cl->next;
   do {
     prev = cur;
     print_point(cur->data);
     cur = cur->next;
   }
   while (prev != cl);
  }
}

/* An exercise */
int length_of_circular_list(list_node *cl) {
  return 0; 
}

list_node *insert_head(list_node *last_node, void *el) {
  list_node *new_node = malloc(sizeof(list_node));
  assert_allocation_success(new_node);

  if (last_node == NULL) {
    return add_to_empty(last_node, el);
  }

  /* Assigning data to new node */
  new_node->data = el;

  /* Setting the new node next pointer to the old last_node next pointer */
  new_node->next = last_node->next;

  /* Setting the last node next pointer to the new node instead */
  last_node->next = new_node;

  return last_node;
}

list_node *insert_tail(list_node *last_node, void *el) {
  list_node *new_node = malloc(sizeof(list_node));
  assert_allocation_success(new_node);

  if (last_node == NULL) {
    return add_to_empty(last_node, el);
  }

  new_node->data = el;

  new_node->next = last_node->next;
  last_node->next = new_node;

  /* Set the last node to the new node which makes the new node the last */
  last_node = new_node;

  return last_node;
}

list_node *add_to_empty(list_node *last_node, void *el) {
  list_node *new_node = malloc(sizeof(list_node));

  if (last_node != NULL) {
    return last_node;
  }

  /* Assigning data to new node */
  new_node->data = el;

  /* Setting the empty last_node pointer to the new node */
  last_node = new_node;

  /* Setting the new node to point to itself (last_node) because there is no other nodes */
  new_node->next = last_node;
  
  return last_node;
}

list_node *delete_head(list_node *last_node) {
  /* Get the head node */
  list_node *head = last_node->next;

  /* Set the last node next to the head next */
  last_node->next = head->next;

  /* Free the head */
  free(head);
  
  return last_node;
}
list_node *delete_tail(list_node *last_node) {
  list_node *current, *new_last_node;

  /* Loop through all nodes until we find that the next node of the current node is actually the last node */
  current = last_node->next;
  do {
    new_last_node = current;
    current = current->next;
  } while (current != last_node);
  
  /* Setting the item before last_node to the last_nodes next node */
  new_last_node->next = last_node->next;

  /* Free the old last node */
  free(last_node);

  return new_last_node;
}

void assert_allocation_success(list_node *ln) {
  if (ln == NULL){
    printf("Cannot allocate list node. Bye\n");
    exit(EXIT_FAILURE);
  }
}
