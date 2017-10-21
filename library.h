
//Add song nodes.
struct node * add_song(struct node *[], char * name, char * artist);

//Search for a song given song and artist name (return a pointer).
struct node * give_song(struct node *[], char * name, char * artist);

//Search for an artist (return a pointer).
struct node * give_artist (struct node *[], char * artist);

//Print out all the entries under a certain letter.
void print_letter (struct node *[], char);

//Print out all the songs of a certain artist
void print_songs (struct node *[], char * artist);

//Print out the entire library.
void print_library (struct node * []);

//Shuffle - print out a series of randomly chosen songs.
void shuffle(struct node * [], int);

//Delete a song
struct node * delete_song (struct node * [], char * name, char * artist);

//Delete all the nodes.
void delete_library(struct node *[]);
