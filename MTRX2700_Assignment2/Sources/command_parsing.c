#include "command_parsing.h"
#include <stdlib.h>
#include <string.h>


  //"`,2,100,A"
  //char **split_up_string = ["`","2","100","A"];
  //is_valid_command = parse_command(char **split_up_string, int num_functions, char command_indicator);  
  //    inside here write functions   



char **split_up_command(char *input_string){
  /*
    This function splits the char array inputted via serial
    into an array of strings, where each command parameter is
    its own element.
  */
  
  int num_tokens, i;
  char **split_string_array;
  char *token;
  
  //Firstly, go through and change all spaces to commas
  for (i = 0; i < strlen(input_string); i++){
  
    if (input_string[i] == ' '){
      
      input_string[i] = ',';
    } 
    //if CR found, change it to NULL terminator then break
    else if ('\r' == input_string[i]){
      
      input_string[i] = '\0';
      break;
    } 
    //commas indicate how many tokens to split up
    else if (',' == input_string[i]){
      num_tokens++;
    }
    else{
    } 
  }
  
  
  //making a 2d array to fit the broken up tokens/param strings
  split_string_array = (char **)malloc(num_tokens*sizeof(char *));
  
  
  //using STRTOK() to split up string and place inside 2d array
  token = strtok(input_string, ",,");
  
  for (i = 0; i < num_tokens; i++){
    
    split_string_array[i] = (char *)malloc(strlen(token)*sizeof(char));
    split_string_array[i] = token;
    
    token = strtok(NULL, ",,");  
    
  }
       
  return split_string_array;
   
}




//int parse_command(char **command)