#ifndef MALLOC_WRAPPER_H
#define MALLOC_WRAPPER_H
#ifdef __cplusplus
extern "C" {
#endif 

#include <stdio.h>
#include <malloc.h>

void *xmalloc(size_t size);
void xfree(void *ptr);

#ifdef __cplusplus
}
#endif // CPLUSPLUS
#endif 
