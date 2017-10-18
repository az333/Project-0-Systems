#include <stdlib.h>
#include <stdio.h>
#include "node.h"

//initialize the table to NULL
void initialize_table () {
  for (int i=0; i<26; i++) table[i] = NULL;
}


void print_list (struct node *head){
  while (head) {
    printf ("Name: %s\nArtist: %s\n\n", head -> name, head -> artist);
    head = head -> next;
  }
}

struct node * insert_front(struct node *head, char * name, char * artist){
  struct node *first = (struct node *)malloc(sizeof(struct node));
  first -> prev = NULL;
  first -> next = head;
  first -> name = name;
  first -> artist = artist;
  return first;
}

struct node * find_song (struct node *head, char * name, char * artist) {
  while (head -> artist != artist && head -> name != name) {
    head = head -> next;
  }
  return head;
}

struct node * find_artist (struct node *head, char * artist) {
  while (head -> artist != artist) {
    head = head -> next;
  }
  return head;
}

struct node * remove_node (struct node *target) {
    target -> prev -> next = target -> next;
    target -> next -> prev = target -> prev;
    return target;
  }

struct node * insert(struct node *, char *, char *){}

struct node * random_song(struct node *){}
