#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List* list =(List*)malloc(sizeof(Item)*50);// allocates memory for the list
  return list;
}

void add_history(List *list, char *str){
  Item *curr_node = list->root; // sets a node to traverse through the list
 
  if(curr_node == NULL){
    Item *new_node = (Item*)malloc(sizeof(Item)); // if list is empty the root is set
    new_node->id = 1; // id number
    new_node->str = copy_str(str,str_len(str)); // command
    new_node->next = NULL; // next pointer
    list->root = new_node; //sets root with new information
    }
  else{
    int new_ID_num = 2; // starts at 2 and is increased to proper ID count
    while(curr_node->next != NULL){
      new_ID_num++; // increases ID counter
      curr_node = curr_node->next; // traverses the list
    }
    curr_node->next= (Item*)malloc(sizeof(Item)); // creates node at the end of the list
    curr_node->next->id= new_ID_num; // stores the ID to the node
    curr_node->next->str= copy_str(str,str_len(str)); // stores the command
  }
}

char *get_history(List *list, int id){
  Item *curr_node = list->root; // sets a node to traverse the list
  while(curr_node->next !=NULL){
    if(curr_node->id == id){ // looks for matching id number and returns it
      return curr_node->str;
    }
    curr_node = curr_node->next; // traverses the list
  }
  printf("id number invalid\n"); // prints if the ID was not found
  return 0;
}

void print_history(List *list){
  Item *curr_node = list->root; //sets a node to traverse the list
  while(curr_node !=NULL){
    printf("%d: %s\n",curr_node->id,curr_node->str); // prints curr_node
    curr_node = curr_node->next; // traverses the list
  }
  printf("Done Printing!\n");
}

void free_history(List *list){
  Item *curr_node = list->root; // sets node to traverse the list
  Item *temp;
  while(curr_node != NULL){
    temp = curr_node; //sets temp to curr_node
    curr_node = curr_node->next; // updates curr_node
    free(temp); // deallocates memory for curr_nodes predecessor
  }
  free(list); // frees the entire list
}

    
    
