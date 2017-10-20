#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "library.h"

//FINISHED
//Add song nodes.
struct node * add_song(struct node * lib[], char * name, char * artist){
  char letter = artist[0] - 97;
  return insert (lib[letter], name, artist);
}


//FINISHED
//Search for a song given song and artist name (return a pointer).
struct node * find_song(struct node * lib[], char * name, char * artist){
  char letter = artist[0] - 97;
  return find_song_node(lib[letter], name, artist);
}


//FINISHED
//Search for an artist (return a pointer).
struct node * find_artist (struct node * lib[], char * artist){
  char letter = *artist - 97;
  return find_artist_node(lib[letter], artist);
}

//FINISHED
//Print out all the entries under a certain letter.
void print_letter (struct node * lib[], char letter) {
  printf ("%c list \n", letter);
  print_list(list[letter]);
}

//Print out all the songs of a certain artist
void print_songs (struct node * lib[], char * artist){
  char letter = *artist - 97;
  struct node * start = find_artist(lib[letter], artist);



}

//FINISHED
//Print out the entire library.
void print_library (struct node * lib[]){
  int i;
  for (i = 97; i < 123; i ++) {
    print_letter(lib, i);
    printf ("\n");
  }
}

//Shuffle - print out a series of randomly chosen songs.
void print_random_songs(struct node * lib[], int num){
}

//FINISHED
//Delete a song
struct node * delete_song (struct node * lib[], char * name, char * artist){
  struct node * song = find_song (lib[*artist - 97], name, artist);
  return remove_node(song);
}

//FINISHED
//Delete all the nodes.
void delete_library(struct node * lib[]){
  int i;
  for (i = 0; i < 26; i ++){
    free_list(lib[i]);
  }
}
