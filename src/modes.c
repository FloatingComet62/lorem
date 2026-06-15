#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modes.h"
#include "words.c"

int word_mode(int length, bool newline, bool capitalize) {
  for (int i = 0; i < length; i++) {
    int index = rand() % WORDS_COUNT;
    char word[1024];
    strncpy(word, words[index],  1024);
    if (i == 0 && capitalize) word[0] += 'A' - 'a';
    if (i == length - 1) printf("%s", word);
    else printf("%s ", word);
  }
  if (newline) printf("\n");
  return 0;
}

int sentence_mode(int length, bool newline) {
  for (int i = 0; i < length; i++) {
    int size = 10 + rand() % 20;
    word_mode(size, false, true);
    printf(". ");
    if (newline) printf("\n");
  }
  return 0;
}

int paragraph_mode(int length, bool newline) {
  for (int i = 0; i < length; i++) {
    int size = 6 + rand() % 10;
    sentence_mode(size, false);
    if (newline) printf("\n\n");
  }
  return 0;
}
