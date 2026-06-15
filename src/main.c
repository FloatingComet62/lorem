#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char *words[] = {
  "a", "ab", "accusamus", "accusantium", "ad", "adipisci", "adipiscing",
  "aliqua", "aliquam", "aliquid", "amet", "anim", "aperiam", "architecto",
  "asperiores", "aspernatur", "assumenda", "at", "atque", "aut", "aute",
  "autem", "beatae", "blanditiis", "cillum", "commodi", "commodo",
  "consectetur", "consequat", "consequatur", "consequuntur", "corporis",
  "corrupti", "culpa", "cum", "cumque", "cupidatat", "cupiditate", "debitis",
  "delectus", "deleniti", "deserunt", "dicta", "dignissimos", "distinctio",
  "do", "dolor", "dolore", "dolorem", "doloremque", "dolores", "doloribus",
  "dolorum", "ducimus", "duis", "ea", "eaque", "earum", "eius", "eligendi",
  "elit", "enim", "eos", "error", "esse", "est", "et", "eu", "eum", "eveniet",
  "ex", "excepteur", "excepturi", "exercitation", "exercitationem", "expedita",
  "explicabo", "facere", "facilis", "fuga", "fugiat", "fugit", "harum", "hic",
  "id", "illo", "illum", "impedit", "in", "incidunt", "incididunt", "inventore",
  "ipsum", "irure", "iste", "itaque", "labore", "laboriosam", "laboris",
  "laborum", "laudantium", "libero", "lorem", "magna", "magnam", "magni",
  "maiores", "maxime", "minima", "minim", "minus", "modi", "molestiae",
  "molestias", "mollitia", "mollit", "nam", "natus", "necessitatibus", "nemo",
  "neque", "nesciunt", "nihil", "nisi", "nobis", "non", "nostrud", "nulla",
  "numquam", "occaecat", "odio", "odit", "officia", "omnis", "optio",
  "pariatur", "perferendis", "perspiciatis", "placeat", "porro", "possimus",
  "praesentium", "proident", "quae", "quaerat", "quam", "quas", "qui", "quia",
  "quibusdam", "quidem", "quis", "quisquam", "quo", "ratione", "recusandae",
  "reiciendis", "rem", "repellat", "repellendus", "reprehenderit",
  "repudiandae", "rerum", "saepe", "sapiente", "sed", "sequi", "similique",
  "sint", "sit", "soluta", "sunt", "suscipit", "tempor", "tempora",
  "temporibus", "tempore", "tenetur", "totam", "ullamco", "ullam", "unde", "ut",
  "vel", "velit", "veniam", "vero", "vitae", "voluptas", "voluptate",
  "voluptatem", "voluptates", "voluptatibus", "voluptatum",
};

#define WORDS_COUNT sizeof(words) / sizeof(char*)

enum {
  MODE_WORD,
  MODE_SENTENCE,
  MODE_PARAGRAPH
};

int word_mode(int length, bool newline, bool capitalize);
int sentence_mode(int length, bool newline);
int paragraph_mode(int length, bool newline);
int print_help();

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

int print_help() {
  printf("usage: lorem [OPTIONS]\n\n");
  printf("positional arguments:\n");
  printf(" mode\t\tgeneration mode: [w]ord, [l]ine/[s]entence, [p]aragraph (default: line)\n");
  printf(" length\t\tnumber of chunks to generate (default: 1)\n");
  printf("\noptions:\n");
  printf(" -h --help\t\tshow this message\n");
  printf("\nexamples:\n");
  printf(" lorem p 2\t\tgenerate 2 paragraphs\n");
  printf(" lorem w 2\t\tgenerate 2 words\n");
  printf(" lorem l 2\t\tgenerate 2 lines/sentences\n");
  printf(" lorem s 2\t\tgenerate 2 lines/sentences\n");
  printf(" lorem 2\t\tgenerate 2 lines/sentences\n");
  printf(" lorem\t\t\tgenerate 1 line/sentence\n");
  printf(" lorem paragraph 2\tgenerate 2 paragraphs\n");
  printf(" lorem word 2\t\tgenerate 2 words\n");
  printf(" lorem line 2\t\tgenerate 2 lines/sentences\n");
  printf(" lorem sentence 2\tgenerate 2 lines/sentences\n");
  return 0;
}
