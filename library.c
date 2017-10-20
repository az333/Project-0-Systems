#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "library.h"

struct node * table[26];

//initialize the table to NULL
void initialize_table (struct node ** table) {
  for (int i=0; i<26; i++) {
    table[i] = NULL;
  }
}
