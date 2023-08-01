#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000

int main(int argc,char*argv[]){
  //get args 
  if (argc != 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }
  FILE *f = fopen(argv[1],"r");
  if(f == NULL){
    printf("ERROR: cannot open file");
  }
  //declarations  
  char memory[MEMORY_SIZE] = {0};
  char *ptr = memory;
  char code[MEMORY_SIZE];
  int code_length = 0;
  //processing code into an array
  while (code_length < MEMORY_SIZE && (code[code_length] = fgetc(f)) != EOF) {
    code_length++;
  }
    code[code_length] = '\0';
    fclose(f);
   
  //Brainfuck
  for (int i = 0; i < code_length; i++) {
    switch (code[i]) {
        case '>': ptr++;
          break;
        case '<': ptr--;
          break;
        case '+':
          (*ptr)++;
          break;
        case '-': (*ptr)--;
          break;
        case '.': putchar(*ptr);
          break;
        case ',': *ptr = getchar();
          break;
        case '[':
          if (*ptr == 0) {
            int loop_count = 1;
            while (loop_count > 0) {
              i++;
              if (code[i] == '[') {
                loop_count++;
              } else if (code[i] == ']') {
                loop_count--;
              }
            }
          }
          break;
        case ']':
          if (*ptr != 0) {
            int loop_count = 1;
            while (loop_count > 0) {
              i--;
              if (code[i] == ']') {
                loop_count++;
              } else if (code[i] == '[') {
                loop_count--;
              }
            }
          }
          break;
        default:
          break;
        }
    }
  return 0; 
}
