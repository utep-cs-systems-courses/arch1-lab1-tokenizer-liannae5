#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List *list = malloc(sizeof(List));// allocates memory for List
  list->root = malloc(sizeof(Item));// allocates memory for item
}

void add_history(List *list, char *str){
  Item *curr_node = list->root;

  if(curr_node == NULL){
      Item *new_node = (Item*)malloc(sizeof(Item));
      new_node->id = 1;
      new_node->str = copy_str(str,str_len(str));
      new_node->next = NULL;
      list->root = new_node;
    }
  else{
    int new_ID_num = 2;
    while(curr_node->next != NULL){
      new_ID_num++;
      curr_node = curr_node->next;
    }
    curr_node->next= (Item*)malloc(sizeof(Item));
    curr_node->next->id= new_ID_num;
    curr_node->next->str= copy_str(str,str_len(str));
  }
}

char *get_history(List *list, int id){
  Item *curr_node = list->root;
  while(curr_node->next !=NULL){
    if(curr_node->id == id){
      return curr_node->str;
    }
    curr_node = curr_node->next;
  }
  printf("id number invalid");
  return 0;
}

void print_history(List *list){
  Item *curr_node = list->root;
  while(curr_node !=NULL){
    printf("%d: %s\n",curr_node->id,curr_node->str);
    curr_node = curr_node->next;
  }
  printf("Done Printing!");
}

void free_history(List *list){
  Item *curr_node = list->root;
  Item *temp;
  while(curr_node != NULL){
    temp = curr_node;
    curr_node = curr_node->next;
    free(temp);
  }
  free(list);
}

    
    
