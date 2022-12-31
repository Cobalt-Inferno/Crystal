#include <util/tempfile.h>

static char *
_gen_tmp_str (char *str, size_t len)
{
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  for (size_t i = 0; i < len; i++) {
    str[i] = rand() % (int) (sizeof charset - 1);
  }
  str[len] = '\0';
  return str;
}

static char *
_alloc_temp_str (size_t size)
{
  char *string = xmalloc(size + 1);
  if (string) {
    _gen_tmp_str(string, size);
  }
  return string;
}

static inline bool
touch (char *filepath)
{
  FILE *file = fopen(filepath, "w");
  if (file) {
    fclose(file);
    return true;
  } else {
    return false;
  }
  return false;
}
static inline bool
rm_tmp (char *path)
{
  if (remove(path) == 0) {
    return true;
  } else {
    return false;
  }
  return false;
}

const temp_t *
init_tempfile (size_t len)
{
  temp_t *temp = xmalloc(sizeof(temp_t));
  const char *path = NULL;
  if ((path = _alloc_temp_str(len)) == NULL) {
    return NULL;
  }
  if (strlen(path) <= PATH_MAX) {
    if (touch( (char*) path)) {
      strcpy((char*)path, temp->path);
    }
  }
  return temp;
}

void
free_tempfile (temp_t *tmp)
{
  if (!tmp) {
    return;
  } else {
    if (!rm_tmp(tmp->path)) {
      return;
    }
    xfree((void*)tmp);
  }
}
