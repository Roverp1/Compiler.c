#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void generate_number(char current, FILE *file) {
  while (current != EOF) {
    printf("%c\n", current);
    current = fgetc(file);
  }
}

void lexer(FILE *file) {
  char current = fgetc(file);

  while (current != EOF) {
    if (current == ';') {
      printf("FOUND SEMICOLON\n");
    } else if (current == '(') {
      printf("FOUND OPEN PAREN\n");
    } else if (current == ')') {
      printf("FOUND CLOSE PAREN\n");
    } else if (isdigit(current)) {
      generate_number(current, file);
      // printf("FOUND DIGIT: %d\n", current - '0');
    } else if (isalpha(current)) {
      printf("FOUND CHARACTER: %c\n", current);
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
