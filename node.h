struct node{
  char * name;
  char * artist;
  struct node *next;
  struct node *prev;
};

void print_list(struct node *);
struct node * insert_front(struct node *, char *, char *);
struct node * insert(struct node *, char *, char *);
struct node * free_list (struct node *);
struct node * remove_node (struct node *);
struct node * find_song (struct node *, char *, char *);
