#include <malloc/malloc_wrapper.h>


void *
xmalloc(size_t size)
{
  void *allocated = malloc(size + 1);
  if (allocated) {
    return allocated;
  } else {
    log_err("crystal.log", true, FF(), "Cannot allocate memory in xmalloc!");
    return NULL;
  }
}

void
xfree(void *ptr)
{
  if (ptr) {
    free(ptr);
  }
}
