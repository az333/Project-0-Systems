#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "library.h"

//Add song nodes.
struct node * add_song(struct node * lib[], char * name, char * artist){
  int index = *artist - 97;
  lib[index] = insert (lib[index], name, artist);
  return lib[index];
}

//Search for a song given song and artist name (return a pointer).
struct node * give_song(struct node * lib[], char * name, char * artist){
  int index = *artist - 97;
  return find_song(lib[index], name, artist);
}

//Search for an artist (return a pointer).
struct node * give_artist (struct node * lib[], char * artist){
  int index = *artist - 97;
  return find_artist(lib[index], artist);
}

//Print out all the entries under a certain letter.
void print_letter (struct node * lib[], char letter) {
  if(!lib[letter-97]){ return; }
  printf ("%c list \n", letter);
  print_list(lib[letter - 97]);
}

//Print out all the songs of a certain artist
void print_songs (struct node * lib[], char * artist){
  int index = *artist- 97;
  struct node *start = find_artist(lib[index],artist);
    while(start && strcmp(artist,start->artist) == 0){
        printf("%s by %s | ",start->name,start->artist);
        start = start->next;
    }
    printf("\n");
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle (struct node * lib[], int num){
  int i = rand() % 26;
  while (num){
    while (!lib[i]){ i = rand() % 26; }
    struct node * random = random_song(lib[i]);
    printf("%s by %s | ", random->name, random-> artist);
    num --;
    i = rand() % 26;
  }
  printf ("\n");
}

//Print out the entire library.
void print_library (struct node * lib[]){
  int i;
  for (i = 97; i < 123; i ++) {
    print_letter(lib, i);
  }
}

//Delete a song
struct node * delete_song (struct node * lib[], char * name, char * artist){
  struct node * song = find_song (lib[*artist - 97], name, artist);
  int index = artist[0] - 97;
  return remove_node(lib[index], song);
}

//Delete all the nodes.
void delete_library(struct node * lib[]){
  int i;
  for (i = 0; i < 26; i ++){
    free_list(lib[i]);
  }
}
