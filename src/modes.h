#ifndef MODES_H
#define MODES_H

#include <stdbool.h>

enum {
  MODE_WORD,
  MODE_SENTENCE,
  MODE_PARAGRAPH
};

int word_mode(int length, bool newline, bool capitalize);
int sentence_mode(int length, bool newline);
int paragraph_mode(int length, bool newline);

#endif // MODES_H
