/*
 * code is incomplete and very ugly, don't judge.
 */
#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define PATH_LIMIT 4096 

void indent(int n, char c) {
  while (n--) {
    putc(c, stdout);
  }
}

char *str_concat(int n, ...) {
  va_list args;
  char *tmp;
  int size = 0;

  va_start(args, n);

  char *result = malloc(PATH_LIMIT + 1);
  if (result == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  char *offset = result;

  for (int i = 0; i < n; i++) {
    tmp = va_arg(args, char *);
    while (*tmp) {
      if (size == PATH_LIMIT) {
        fprintf(stderr, "str_concat error: too large of string\n");
        free(result);
        exit(EXIT_FAILURE);
      }
      *offset = *tmp;
      tmp++;
      offset++;
      size++;
    }
  }
  *offset = '\0';
  return result;
}

void ls_dir(DIR *dp, char *parent_dir, int depth);

void ls_dir(DIR *dp, char *parent_dir, int depth) {
  struct dirent *entry;

  while ((entry = readdir(dp)) != NULL) {
    struct stat fs;
    int r;
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name,".git") == 0) {
      continue;
    }
    char *abs_path = str_concat(3, parent_dir, "/", entry->d_name); 
    r = stat(abs_path, &fs);
    if (r == -1) {
      fprintf(stderr, "Error reading file %s\n", abs_path);
      exit(EXIT_FAILURE);
    }

    if (S_ISREG(fs.st_mode)) {
      indent(depth, '\t');
      printf("File: %s\n", abs_path);
    } else if (S_ISDIR(fs.st_mode)) {
      DIR *dp;
      dp = opendir(abs_path);
      if (dp == NULL) {
        fprintf(stderr, "Error opening dir %s\n", abs_path);
        exit(EXIT_FAILURE);
      } else {
        indent(depth, '\t');
        printf("Dir: %s\n", abs_path);
        ls_dir(dp, abs_path, depth+1);
        free(abs_path);
      }
    }
  }
}

int main() {
  DIR *dp;
  char d_name[] = "/home/tyler/code/personal/dotfiles";

  dp = opendir(d_name);

  if (dp == NULL) {
    fprintf(stderr, "Error opening dir %s\n", d_name);
    exit(EXIT_FAILURE);
  }
  ls_dir(dp, d_name, 0);

  closedir(dp);
  return EXIT_SUCCESS;
}