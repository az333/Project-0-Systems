#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"

//FINISHED
//finds length of list
int find_length (struct node *head) {
  int i = 0;
    while(head){
        head = head -> next;          i++;
    }
    return i;
}


//FINISHED
//insert nodes in order (alphabetical by artist)
void *add_song(char name[], char artist[]) {

}

//FINISHED (??)
//insert nodes at the front
struct node * insert_front(struct node *head, char * name, char * artist){
  struct node *first = (struct node *)malloc(sizeof(struct node));
  first -> prev = NULL;
  first -> next = head;
  first -> name = name;
  first -> artist = artist;
  return first;
}

//FINISHED (??)
//remove a single specified node from the list
struct node * remove_node (struct node *target) {
    target -> prev -> next = target -> next;
    target -> next -> prev = target -> prev;
    free(target);
    target = NULL;
    return target;
}

//FINISHED
//print the entire list
void print_list (struct node *head){
  while (head) {
    printf ("Artist: '%s', Name: '%s' | ", head -> name, head -> artist);
    head = head -> next;
  }
  printf("\n");
}

//FINISHED
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

//FINISHED
//find and return a pointer to the first song of an artist based on artist name
struct node * find_artist (struct node *head, char * artist) {
  while (head) {
    if (!(strcmp(head -> artist,artist))) {
      return head;
    }
    head = head -> next;
  }
  return head;
}

//FINISHED
//Return a pointer to random element in the list.
struct node * random_song(struct node * head){
  int length = find_length(head);
  //random number from 0 to length
  int random = rand() % length;
  while (random) {
    head = head -> next;
    random --;
  }
  return head;
}

//FINISHED
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
