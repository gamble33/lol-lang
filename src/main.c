#include "include/lol.h"
#include "include/io.h"

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Specify file path...");
    return 1;
  }
  char* src = read_file_src(argv[1]);
  lol_compile(src);
  free(src);
  return 0;
}
