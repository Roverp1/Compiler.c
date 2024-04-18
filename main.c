#include <stdio.h>
#include <stdlib.h>

typedef enum {
  SEMI,
  OPEN_PAREN,
  CLOSE_PAREN,
} TypeSeparator;

typedef enum {
  EXIT,
} TypeKeyword;

typedef enum {
  INT,
} TypeLiteral;

typedef struct {
 TypeKeyword type; 
} TokenKeyword;

typedef struct {
  TypeLiteral type; 
  int value;
} TokenLiteral;

typedef struct {
 TypeSeparator type; 
} TokenSeparator;

void lexer(FILE *file) {
  char current = fgetc(file);

  while (current != EOF) {
    if (current == ';') {
      printf("FOUND SEMICOLON\n");
    }

    // printf("%c", current);
    current = fgetc(file);
  }
}

int main() {
  FILE *file;
  file = fopen("test.unn", "r");

  lexer(file);
}
