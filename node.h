struct node{
  char * name;
  char * artist;
  struct node *next;
  struct node *prev;
};

//insert nodes at the front
struct node * insert_front(struct node *, char *, char *);

//insert nodes in order
struct node * insert(struct node *, char *, char *);

//print the entire list
void print_list(struct node *);

//find and return a pointer to a node based on artist and song name
struct node * find_song(struct node *, char *, char *);

//find and return a pointer to the first song of an artist based on artist name
struct node * find_artist(struct node *, char *);

//Return a pointer to random element in the list.
struct node * random_song(struct node *);

//remove a single specified node from the list
struct node * remove_node (struct node *, struct node *);

//free the entire list
struct node * free_list (struct node *);



//helper functions

struct node * find_place (struct node * head, char * name, char * artist);

struct node * insert_after (struct node * head, struct node* location, char * name, char * artist);

struct node * insert_before (struct node * head, struct node *location, char *name, char *artist);

struct node * create_node (char * name, char * artist);

int find_length (struct node * head);
