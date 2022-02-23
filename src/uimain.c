#include <stdio.h>
#include  <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main()
{
  puts("Hello!");
  List *history = init_history();
  
  while(1){

    fputs("Type '!h' to print history,'!<num>' for specfic id, # to tokenize, or *' to exit the program \n$ ", stdout);
    fflush(stdout);
    char words[100];
    int c;
    while((c = getchar()) == '\n');
    if(c == EOF)
      goto done;
    switch(c){
    case '!':
      fgets(words,100,stdin);
      char *temp1 = words;
      add_history(history,temp1);
      if(words[0] != 'h'){
	printf("here is the chosen id\n");
	printf(get_history(history,atoi(words)));
      }
      else{
	print_history(history);
      }
      break;
    case '#':
      printf("You chose tokenize\n");
      fgets(words, 100, stdin);
      char *temp2 =words;
      add_history(history,temp2);
      char **tokens = tokenize(words);
      printf("This is the list:\n ");
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case '*':
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
