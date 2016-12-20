/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // definig a tries
    typedef struct node
    {
        bool word;
        struct node* chil[27];            // 27 due to 26 characters and apostrophe
    }
    node;
    node* root = malloc(sizeof(node));
    
    // stores  current location in loca and remeber character number in index
    node* loca;
    index=0;
    // opening the dictionary file for loading.
    FILE* fp = fopen(dictionary,"r");
    for(int c=fgetc(fp);c != EOF;c=fgetc(fp))
    {
        // first character of word should go to root
        if(isalpha(c)&&index=0)
        {
            int num=(c-'a');
            node->children[num]=malloc(sizeof(node));
            loca=node->chil[num];
        }
        else if(isalpha(c))
        {
            int num=(c-'a');
            loca->chil[num]=malloc(sizeof(node));
            loca=loca->chil[num];
        }
        // takeing care of apostorhe
        else if(c=='\'')
        {
            loca->chil[26]=malloc(sizeof(node));
            loca=loca->chil[26];
        }
        // and if we encountered a \n then it means the word ended
        else
        {
            loca->word=true;
            index=0;
        }
    }
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
