#include <malloc/malloc_wrapper.h>


void *
xmalloc(size_t size)
{
  void *allocated = malloc(size + 1);
  if (allocated) {
    return allocated;
  } else {
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
