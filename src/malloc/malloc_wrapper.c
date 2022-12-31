#include "util/log/logger.h"
#include <malloc/malloc_wrapper.h>


void *
xmalloc(size_t size)
{
  log_debug("crystal.log", true, FF(), "Allocating %d bytes.", size);
  void *allocated = malloc(size - 1);
  if (allocated != NULL) {
    return allocated;
  } else {
    log_err("crystal.log", true, FF(), "Cannot allocate memory in xmalloc!");
    return NULL;
  }
}

void
xfree(void *ptr)
{
  free(ptr);
}
