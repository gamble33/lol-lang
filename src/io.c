#include "include/io.h"

char* read_file_src(const char* path) {
  FILE* file;
  char* line = NULL;
  size_t length = 0;
  ssize_t read;

  file = fopen(path, "rb");
  if(file == NULL) {
    printf("Couldn't read file `%s`\n", path);
    exit(1);
  }

  char* buf = (char*) calloc(1, sizeof(char));
  buf[0] = '\0';

  while((read = getline(&line, &length, file)) != -1) {
    buf = (char*) realloc(buf, (strlen(buf) + strlen(line) + 1) * sizeof(char));
    strcat(buf, line);
  }

  fclose(file);
  if(line) {
    free(line);
  }
  return buf;
}
