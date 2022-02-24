#include <stdio.h>
#include  <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main()
{
  puts("Hello!");
  List *history = init_history(); // creates history list
  
  while(1){

    fputs("Type '!h' to print history,'!<num>' for specfic id, # to tokenize, or *' to exit the program \n$ ", stdout);
    fflush(stdout);
    char words[100];
    int c;
    while((c = getchar()) == '\n');
    if(c == EOF)
      goto done;
    switch(c){
    case '!': // history commands
      fgets(words,100,stdin); // gets string input
      char *temp1 = words;
      add_history(history,temp1); // adds string to history
      if(words[0] != 'h'){ // looks for id 
	printf("Here is the chosen id:\n\n");
	printf(get_history(history,atoi(words))); // returns result of get_history
	printf("\n");
      }
      else{
	print_history(history); // prints entire history if words[0] = 'h'
      }
      break;
    case '#': // tokenize command
      printf("You chose tokenize\n");
      fgets(words, 100, stdin); // gets string input
      char *temp2 =words;
      add_history(history,temp2); // adds to list history
      char **tokens = tokenize(words); // tokenizes the string
      printf("This is the list:\n ");
      print_tokens(tokens); // prints the tokens
      free_tokens(tokens); // deallocates memory for the tokens
      break;
    case '*': // quits the program
      puts("Goodbye!");
      goto done;
      break;
    default:

      printf("Unrecognized input");
    }
 
  }
 done:
  free_history(history);
  return 0;
}
