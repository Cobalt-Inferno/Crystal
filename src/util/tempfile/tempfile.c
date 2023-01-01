#include <util/tempfile/tempfile.h>

static char *
_gen_tmp_str (char *str, size_t len)
{
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  str[0] = '/';str[1] = 't';str[2] = 'm';str[3] = 'p';str[4] = '/'; // Start in /tmp/

  for (size_t i = 5; i < len; i++) {
    str[i] = charset[rand() % (int) (sizeof charset - 1)];
  }
  str[len] = '\0';
  return str;
}

static char *
_alloc_temp_str (size_t size)
{
  char *string = xmalloc(size - 1);
  if (string) {
    strcat(string, _gen_tmp_str(string, size));
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

const temp_t
init_tempfile (size_t len)
{
  temp_t temp;
  char *path = NULL;
  if ((path = _alloc_temp_str(len)) == NULL) {
    log_err("crystal.log", true, FF(), "Cannot allocate memory!");
  }
  if (strlen(path) <= PATH_MAX) {
    if (touch( (char*) path)) {
      strcpy(temp.path, path);
    }
  }
  return temp;
}

void
free_tempfile (temp_t *tmp)
{
  if (rm_tmp(tmp->path)) {
    xfree(tmp);
  }
}
const char *
tmp_to_var (const char *path)
{
  int fp = open(path, 0);
  struct stat st;
  if (fstat(fp,&st) == -1) {
    log_debug("crystal.log", true, FF(), "Could not use fstat!");
    return NULL;
  }
  char *buff = mmap(NULL, (size_t) st.st_size, PROT_READ, MAP_PRIVATE, fp, 0);
  return buff;
}
