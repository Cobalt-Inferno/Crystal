
#ifndef TEMPFILE_H 
#define TEMPFILE_H
#ifdef __cplusplus
extern "C" {
#endif 

#include <stdbool.h>
#include <stdio.h>
#include <malloc/malloc_wrapper.h>
#include <util/log/logger.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#define PATH_MAX 4096


typedef struct {
  char path[PATH_MAX];
} temp_t;



const temp_t *init_tempfile (size_t len);
void free_tempfile (temp_t *tmp);
const char *tmp_to_var (const char *path);

#ifdef __cplusplus
}
#endif // CPLUSPLUS
#endif 
