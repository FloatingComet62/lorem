#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "modes.h"
#include "help.h"

#define IS_WORD(x) ( \
    (strcmp(x, "w") == 0) || \
    (strcmp(x, "word") == 0) \
  )
#define IS_LINE(x) ( \
    (strcmp(x, "l") == 0) || \
    (strcmp(x, "s") == 0) || \
    (strcmp(x, "line") == 0) || \
    (strcmp(x, "sentence") == 0) \
  )
#define IS_PARA(x) ( \
    (strcmp(x, "p") == 0) || \
    (strcmp(x, "para") == 0) || \
    (strcmp(x, "paragraph") == 0) \
  )

int main(int argc, char **argv) {
  int mode = MODE_SENTENCE;
  int length = 1;

  if (
    argc >= 2 && (
      strcmp(argv[1], "help") == 0 ||
      strcmp(argv[1], "h") == 0 ||
      strcmp(argv[1], "--help") == 0 ||
      strcmp(argv[1], "-h") == 0
    )
  ) {
    return print_help();
  }

  if (argc == 2) {
    if (IS_LINE(argv[1])) {
      mode = MODE_SENTENCE;
    } else if (IS_PARA(argv[1])) {
      mode = MODE_PARAGRAPH;
    } else if (IS_WORD(argv[1])) {
      mode = MODE_WORD;
    } else {
      length = atoi(argv[1]);
    }
  } else if (argc == 3) {
    if (IS_LINE(argv[1])) {
      mode = MODE_SENTENCE;
    } else if (IS_PARA(argv[1])) {
      mode = MODE_PARAGRAPH;
    } else if (IS_WORD(argv[1])) {
      mode = MODE_WORD;
    }
    length = atoi(argv[2]);
  }
  
  srand(time(NULL));
  if (mode == MODE_WORD) return word_mode(length, true, false);
  printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ");
  if (mode == MODE_SENTENCE) {
    printf("\n");
    return sentence_mode(length - 1, true);
  }
  return paragraph_mode(length, true);
}

#include "modes.c"
#include "help.c"
