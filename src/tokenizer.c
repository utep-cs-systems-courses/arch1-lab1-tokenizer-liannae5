#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int str_len(char *str){
  int count = 0;
  int i = 0;
  while(str[i] != '\0'){
    count++;
    i++;
  }
  return count;
}

int space_char(char c){

  if(c == ' ' || c == '\t' && c != '\0'){
    return 1; // Returns true if the char is a space
  }
  return 0; // Otherwise returns false
}

int non_space_char(char c){

  if(c != ' ' && c != '\t' && c != '\0'){
    return 1; // Returns true if the char is not a space
  }
  return 0;// Otherwise returns false
}

char *word_start(char *str){
  while(space_char(*str)){
    str += 1; // iterates through a string until the beginning of a word is found
  }
  return str; // returns index
}

char *word_terminator(char *word){
  while(non_space_char(*word)){
    word += 1; // iterates through a string until the end of a word
  }
  return word; // returns index after a word ends
}


int count_words(char *str){
  int count = 0;
  while(*str != '\0'){
    str =  word_start(str); // finds start of a new word
    count++; // adds 1 to count when a new word is found 
    str = word_terminator(str); // updates str to start after the current word is counted
  }
  return count; // returns final count of all words
}


char *copy_str(char *inStr, short len){
  char *copyS =(char*) malloc((len+1)*sizeof(char)); // allocates memory for copy
  int i = 0;
  while(i < len){ // copies each char into copyS
    copyS[i] = inStr[i];
    i++;
  }
  *(copyS +i) = '\0'; // ends copyS with the needed 0
  return copyS; // returns a copy of the string
}

char **tokenize(char* str){
  int num_words = count_words(str); // stores the word count of str
  char **tokens = (char**) malloc((num_words+1)*sizeof(char*)); // allocates memory for tokens
  int token_len; // holds length of given word
  int i;
  for(i = 0; i< num_words; i++){
    char *start_word = word_start(str); // holds start of a word
    char *end_word = word_terminator(start_word); // holds end of a word
    token_len = end_word - start_word;// holds length of a word
    char *new_token = copy_str(start_word,token_len); // stores a copy of the current word
    tokens[i] = new_token; // inserts new word as a token in the token array
    str = end_word; // updates str
  }
  tokens[i] = '\0'; // ends array with necessary null terminator

  return tokens; // returns finished tokens array with all new tokens
}
    
void print_tokens(char **tokens){
  int i = 0;
  while(*tokens != NULL){
    printf("tokens[%d] = \"%s\"\n", i, *tokens);
    i++; // increases representative index for each token
    tokens++; // increases pointer to next token
  }
  printf("Done printing!\n");
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){ // iterates through each token
    free(tokens[i]); // deallocates memory of each token
    i++;
  }
  free(tokens); // deallocates memory of tokens itself
}
    
    
    
  
