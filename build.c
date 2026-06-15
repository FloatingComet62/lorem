#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>

#define CC "gcc", "-O3"

int status;

#define RUN_CMD(...) do { \
  if (fork() == 0) { \
    char* args[] = __VA_ARGS__; \
    print_cmd(args); \
    execvp(args[0], args); \
    return 0; \
  } else { \
    wait(&status); \
  } \
} while (0);

void print_cmd(char** args) {
  int i = 0;
  while (args[i] != NULL) {
    printf("%s ", args[i++]);
  }
  printf("\n");
}


// https://github.com/tsoding/nob.h/blob/0a08926d8094fc4ae678155c5d73ae21d1f96f3f/nob.h#L2413
int needs_rebuild(char* bin_file, char* source_file) {
  struct stat statbuf = {0};
  if (stat(bin_file, &statbuf) < 0) {
    if (errno == ENOENT) return 1;
    return -1;
  }
  time_t output_path_time = statbuf.st_mtime;

  if (stat(source_file, &statbuf) < 0) {
    fprintf(stderr, "could not stat %s: %s", source_file, strerror(errno));
    return -1;
  }

  time_t input_path_time = statbuf.st_mtime;
  return input_path_time > output_path_time;
}

int main(int argc, char** argv) {
  if (needs_rebuild(argv[0], __FILE__)) {
    RUN_CMD({CC, __FILE__, "-o", argv[0], NULL});
    if (status != 0) {
      // cc error
      return 0;
    }
    print_cmd(argv);
    execvp(argv[0], argv);
  }

  RUN_CMD({CC, "src/main.c", "-o", "lorem", NULL});
  char* args[] = {"./lorem", NULL};
  print_cmd(args);
  execvp(args[0], args);
}
