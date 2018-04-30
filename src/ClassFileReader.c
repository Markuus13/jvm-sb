#include "../includes/JavaClassStructures.h"

JavaClass* read_class_file(char const* file_path);
uint32_t read_4_bytes(FILE* fp);

int main(int argc, char const *argv[]) {
  read_class_file(argv[1]);
  return 0;
}

JavaClass* read_class_file(char const* file_path) {
  FILE *file = fopen(file_path, "rb");

  if (file == NULL) {
    printf("File not found. Shutting down.\n");
    exit(1);
  }

  JavaClass *class_file = (JavaClass *) malloc(sizeof(JavaClass));
  class_file->magic_number = read_4_bytes(file);

  printf("Magic Number: 0x%0X \n", class_file->magic_number);
}

uint32_t read_4_bytes(FILE* fp) {
  uint32_t bytes_read = getc(fp);
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  bytes_read = (bytes_read << 8) | (getc(fp));
  return bytes_read;
}
