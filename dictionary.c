/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"


// declared it as global so that it can be used in all functions
  typedef struct node
    {
        bool word;
        struct node* chil[27];            // 27 due to 26 characters and apostrophe
    }
    node;
    node* root = malloc(sizeof(node));

/**
 * Returns true if word is in dictionary else false.
 */
 
bool check(const char* word)
{
    // checking lenth of string
    int len=strlen(word);
    
    node* loca1;
    int index=0;
    for(index;index<len+1;index++)
    {
        // if index=len the we should check if word exist
        if(index==len)
        {
            if(loca1->word)
            {
                return true;
            }
            else
            {
                return false;
            }
        }    
        // making character to integer to use function like isalpha
        int c=word[index];
        int num= c-'a';
        //if is alpha then its between 0-25 and else its a apsotrophe so 26
        if(isalpha(c)&&index==0)
        {
            loca1=root->chil[num];
        }
        else if(isalpha(c))
        {
            loca1=loca1->chil[num];
            
            // if loca1 becomes null then word doesnt exist
            if(loca1==NULL)
            {
                return false;
            }
        }
        else
        {
            loca=loca->chil[26];
            if(loca1==NULL)
            {
                return false;
            }
        }
    }    
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
// totale words load 
int count=0;
    
bool load(const char* dictionary)
{
    // definig a tries
    // stores  current location in loca and remeber character number in index
    node* loca;
     int index=0;
    // opening the dictionary file for loading.
    FILE* fp = fopen(dictionary,"r");
    if(fp==NULL)
    {
        printf("error in opening dictionary file");
        return false;
    }
    
    for(int c=fgetc(fp);c != EOF;c=fgetc(fp))
    {
        // first character of word should go to root
        if(isalpha(c)&&index=0)
        {
            int num=(c-'a');
            node->children[num]=malloc(sizeof(node));
            loca=node->chil[num];
            index++;
        }
        else if(isalpha(c))
        {
            int num=(c-'a');
            loca->chil[num]=malloc(sizeof(node));
            loca=loca->chil[num];
            index++;
        }
        // takeing care of apostorhe
        else if(c=='\'')
        {
            loca->chil[26]=malloc(sizeof(node));
            loca=loca->chil[26];
            index++;
        }
        // and if we encountered a \n then it means the word ended
        else
        {
            loca->word=true;
            count++;
            index=0;
        }
    }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // pointer to memory
    node* fre=root;
    // int to keep track of chil number we are at
    int tra=0;
    for(tra;tra<27;tra++)
    {
        if(fre->chil[tra]!=NULL)
        {
            clear(fre->chil[tra]);
        }
    }
    return true;
}

clear(node* current)
{
    for(int i=0;i<27;i++)
    {
        if(current->chil[i]!=NULL)
        {
            clear(current->chil[i]);
        }
    }
    free(current);
}