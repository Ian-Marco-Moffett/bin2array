#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>


void process(const char* filename) {
  FILE* fp = fopen(filename, "r");

  if (!(fp)) {
    /*
     *  The file must not exist.
     *  Throw an error.
     *
     */ 

    perror("bin2array");
    exit(1);
  }

  /*
   *  Fetch the file size.
   */
  fseek(fp, 0, SEEK_END);
  size_t file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  /*
   *  We will now read the file
   *  into a buffer.
   *
   */
  char* buf = calloc(file_size + 1, sizeof(char));
  fread(buf, sizeof(char), file_size, fp);

  /*
   *  Print out the array.
   */
  printf("uint8_t arr[] = {");
  for (size_t i = 0; i < file_size; ++i) {
    printf("0x%02x", (uint8_t)buf[i]);

    if (i < file_size - 1) {
      printf(", ");
    }

    if (i % 9 == 0) {
      printf("\n\t");
    }
  }

  printf("};\n");

  /*
   *  Now we are done, so we must
   *  cleanup what we have done.
   *
   */

  free(buf);
  fclose(fp);

  /*
   *  Some newlines in case 
   *  multiple arrays.
   */

  printf("\n\n");
}


int main(int argc, const char** argv) {
  /*
   *  Ensure the correct amount of arguments.
   *
   */

  if (argc < 2) {
    printf("Too few arguments!\n");
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    process(argv[i]);
  }

  return 0;
}
