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

int main() {
  TokenLiteral token;
  token.type = INT;
  token.value = 5;
  printf("%d\n", token.value);
}
