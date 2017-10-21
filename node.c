#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "node.h"

struct node * create_node (char * name, char * artist) {
  struct node * this = (struct node *)malloc(sizeof(struct node));
  this -> prev = NULL;
  this -> next = NULL;
  this -> name = name;
  this -> artist = artist;
  return this;
}

//finds length of list
int find_length (struct node *head) {
  int i;
  for(i = 0; head; i ++) head = head -> next;
  return i;
}

//insert nodes in order (alphabetical by artist)
struct node * insert(struct node * head, char * name, char * artist) {
  if (head == NULL) {
    head = create_node(name, artist);
    return head;
  }
  if (strcmp(artist, head -> artist) < 0){ //new artist is alphabetically before the current first
    return insert_front(head, name, artist);
  }
  struct node * location = find_place (head, name, artist);
  if (!strcmp(artist, location -> artist) && strcmp(name, location -> name) < 0) {
    return insert_before(head, location, name, artist);
  }
  return insert_after (head, location, name, artist);
}

//the given song should go right after the node that this function returns
struct node * find_place (struct node * head, char * name, char * artist) {
  //new artist is alphabetically later than current artist
  while (head -> next && strcmp(artist, head -> next -> artist) > 0) head = head -> next;
  // artist is the same but new name is alphabetically later than current name
  while (head -> next && !strcmp(artist, head -> next -> artist) && strcmp(name, head -> next -> name) > 0) head = head -> next;
  return head;
}

struct node * insert_after (struct node * head, struct node* location, char * name, char * artist) {
    struct node * this = create_node (name, artist);
    if (location -> next != NULL) {
      location -> next -> prev = this;
      this -> next = location -> next;
    }
      this -> prev = location;
      location -> next = this;
    return head;
}

struct node * insert_before (struct node * head, struct node *location, char *name, char *artist) {
  if (location -> prev) return insert_after (head, location -> prev, name, artist);
  return insert_front (head, name, artist);
}

//insert nodes at the front
struct node * insert_front(struct node *head, char * name, char * artist){
  struct node * first = create_node (name, artist);
  first -> prev = NULL;
  first -> next = head;
  head -> prev = first;
  return first;
}

//remove a single specified node from the list
struct node * remove_node (struct node * head, struct node *target) {
  if(head == NULL || target == NULL){
    return head;
  } if (head == target) {
    head = target -> next;
  } if (target -> next != NULL){
    target -> next -> prev = target -> prev;
  } if (target -> prev != NULL){
    target -> prev -> next = target -> next;
  }
  free(target);
  target = NULL;
  return head;
}

//print the entire list
void print_list (struct node *head){
  while (head) {
    printf ("Artist: '%s', Name: '%s' | ", head -> artist, head -> name);
    head = head -> next;
  }
  printf("\n");
}

//find and return a pointer to a node based on artist and song name
struct node * find_song (struct node *head, char * name, char * artist) {
  while (head) {
    if (!(strcmp (head -> artist, artist)) && !(strcmp(head -> name, name))) {
      return head;
    }
    head = head -> next;
  }
  return head;
}

//find and return a pointer to the first song of an artist based on artist name
struct node * find_artist (struct node *head, char * artist) {
  while (head) {
    if (!(strcmp(head -> artist, artist))) {
      return head;
    }
    head = head -> next;
  }
  return head;
}

//Return a pointer to random element in the list.
struct node * random_song(struct node * head){
  int length = find_length(head);
  int random = rand() % length;
  while (random) {
    head = head -> next;
    random --;
  }
  return head;
}

//free the entire list
struct node * free_list (struct node * p){
  struct node *head = p;
  while (head){
    struct node *temp = head;
    head = head -> next;
    free(temp);
  }
  p = NULL;
  return p;
}
