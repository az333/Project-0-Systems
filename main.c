#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "node.h"
#include "library.h"

int main () {

   srand(time(NULL));
   struct node * head = create_node ("song2", "artist2");
   //printf ("HEAD ADDRESS: %p\n", head);
   printf("////////// LINKED LIST TESTS ////////// \n\n");
   printf("============================\n");
   printf("Testing print_list() .... \n\n");
   printf("Print current list:\n");
   print_list(head);

   printf("============================\n");
   printf("Testing insert_front() ... \n");
   printf("\n");
   printf("Insert song1 in front of song2:\n");
   head = insert_front(head, "song1", "artist1");
   print_list(head);

   printf("============================\n");
   printf("Testing insert in correct order ... \n\n");
   printf("Insert songs in order:\n");
   head = insert(head,"song4","artist4");
   head = insert(head,"song12","artist1");
   head = insert(head,"song3","artist3");
   head = insert(head,"song5","artist5");
   head = insert(head,"song","artist");
   //head = insert(head,"blah","blach");
   //head = insert(head,"abc","blach");
   print_list(head);
   printf("List length: %d\n",find_length(head));



   printf("============================\n");
   printf("Testing find song ... \n\n");
   printf("Finding song10 by artist10: \n");
   struct node* test = find_song(head,"song10","artist10");
   if (test != NULL) {
     printf("song name: %s, artist: %s\n", test->name, test->artist);
   } else {
     printf ("Song does not exist!\n");
   }

   printf("============================\n");
   printf("Testing random song generator ...\n\n");
   struct node * random1 = random_song(head);
   struct node * random2 = random_song(head);
   struct node * random3 = random_song(head);

   printf("Random song from list: %s by %s \n", random1->name, random1 -> artist);
   printf("Random song from list: %s by %s \n", random2->name, random2 -> artist);
   printf("Random song from list: %s by %s \n", random3->name, random3 -> artist);

   printf("============================\n");
   printf("Testing remove song ... \n\n");
   printf("Removed [song, artist] from list:\n");
   struct node * gone = find_song(head, "song", "artist");
   head = remove_node(head, gone);
   print_list(head);

   printf("\nRemoved [song2, artist2] from list:\n");
   struct node * gone2 = find_song(head, "song2", "artist2");
   //printf("GONE2 PREV: %s by %s\n", gone2 -> prev -> name, gone2 -> prev -> artist);
   head = remove_node(head, gone2);
   print_list(head);

   printf("\nRemoved [song5, artist5] from list:\n");
   struct node * gone3 = find_song(head, "song5", "artist5");
   //printf("GONE3 PREV: %s by %s\n", gone3 -> prev -> name, gone3 -> prev -> artist);
   head = remove_node(head, gone3);
   print_list(head);

   printf("============================\n\n");
   printf("Testing free_list() .... \n");
   printf("Freed List:\n");
   head = free_list(head);
   print_list(head);


   //initialize array values to null
   struct node * lib[26];
   int i = 0;
   while(i < 26){lib[i]=0; i++;}

   printf("////////// LIBRARY TESTS //////////\n\n");
   printf("============================\n");
   printf("Print current empty list:\n");
   print_library(lib);

   printf("\nAdded first song:\n");
   add_song(lib, "song1", "artist1");
   print_library(lib);


   printf("============================\n");
   printf("Testing add songs ... \n\n");
   printf("Add some songs:\n");
   add_song(lib,"crazy dazy", "angelica");
   add_song(lib,"one two three","casim");
   add_song(lib,"little star","angelica");
   add_song(lib,"twinkle","angelica");
   add_song(lib,"happy song", "casim");
   add_song(lib,"abc", "cama");
   add_song(lib,"love song", "us");
   add_song(lib,"sad song","casim");
   //printf("it should print out 8 entries in order:\n");
   print_library(lib);


   printf("============================\n");
   printf("Testing print by artist ... \n\n");
   printf("Printing angelica's songs: \n");
   print_songs(lib,"angelica");


   printf("============================\n");
   printf("Testing shuffle ...\n\n");
   printf("Five random songs: \n");
   shuffle(lib, 5);


   printf("============================\n");
   printf("Testing delete song ... \n\n");
   printf("Deleting abc by casim\n");
   delete_song(lib,"abc","casim");
   printf("Printing casim's songs after deletion:\n");
   print_songs(lib,"casim");

   printf("============================\n");
   printf("Testing search function ...\n\n");
   printf("Searched for twinkle by angelica and got: \n");
   struct node * search = give_song(lib, "twinkle","angelica");
   printf("%s by %s \n",search-> name, search-> artist);

  return 0;

}
