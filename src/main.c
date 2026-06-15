#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "modes.h"
#include "help.h"

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
    length = atoi(argv[1]);
  } else if (argc == 3) {
    if (
      (strcmp(argv[1], "l") == 0) ||
      (strcmp(argv[1], "line") == 0) ||
      (strcmp(argv[1], "s") == 0) ||
      (strcmp(argv[1], "sentence") == 0)
    ) {
      mode = MODE_SENTENCE;
    } else if (
      (strcmp(argv[1], "p") == 0) ||
      (strcmp(argv[1], "para") == 0) ||
      (strcmp(argv[1], "paragraph") == 0)
    ) {
      mode = MODE_PARAGRAPH;
    } else if (
      (strcmp(argv[1], "w") == 0) ||
      (strcmp(argv[1], "word") == 0)
    ) {
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
