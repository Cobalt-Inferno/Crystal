
#ifndef TEMPFILE_H 
#define TEMPFILE_H
#ifdef __cplusplus
extern "C" {
#endif 

#include <stdbool.h>
#include <stdio.h>
#include <malloc/malloc_wrapper.h>
#include <string.h>
#include <stdlib.h>
#define PATH_MAX 4096


typedef struct {
  char path[PATH_MAX];
} temp_t;



const temp_t *init_tempfile (size_t len);
void free_tempfile (temp_t *tmp);

#ifdef __cplusplus
}
#endif // CPLUSPLUS
#endif 
