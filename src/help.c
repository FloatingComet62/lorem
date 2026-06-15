#include <stdio.h>

#include "help.h"

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
  printf(" lorem p\t\tgenerate 1 paragraph\n");
  printf(" lorem paragraph 2\tgenerate 2 paragraphs\n");
  printf(" lorem word 2\t\tgenerate 2 words\n");
  printf(" lorem line 2\t\tgenerate 2 lines/sentences\n");
  printf(" lorem sentence 2\tgenerate 2 lines/sentences\n");
  return 0;
}
