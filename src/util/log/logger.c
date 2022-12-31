#include <util/log/logger.h>

static const char *
omit_last_end(char *path)
{
  char *tmp = malloc(MAX_MSG);
  strcpy(tmp, path);
  if (path[strlen(path) - 1] == '\n') {
    tmp[strlen(path) - 1] = '\0';
  }
  return tmp;
}


static char *
fetch_time()
{
  time_t raw;
  struct tm *tf;
  time(&raw);
  tf = localtime(&raw);
  return asctime(tf);
}


static inline void 
log_info (char *logpath, bool _stdout, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  const char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %s) -- INFO: %s", time, __FILE__, __LINE__, str);
      fprintf(f, "%s -- %s (LINE: %s) -- INFO: %s", time, __FILE__, __LINE__, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %s) -- INFO: %s", time, __FILE__, __LINE__, str);
    }
  }
  free(time);
  fclose(f);
}
static inline void 
log_debug (char *logpath, bool _stdout, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  const char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %s) -- DEBUG: %s", time, __FILE__, __LINE__, str);
      fprintf(f, "%s -- %s (LINE: %s) -- DEBUG: %s", time, __FILE__, __LINE__, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %s) -- DEBUG: %s", time, __FILE__, __LINE__, str);
    }
  }
  free(time);
  fclose(f);
}
static inline void 
log_err (char *logpath, bool _stdout, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  const char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %s) -- ERROR: %s", time, __FILE__, __LINE__, str);
      fprintf(f, "%s -- %s (LINE: %s) -- ERROR: %s", time, __FILE__, __LINE__, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %s) -- ERROR: %s", time, __FILE__, __LINE__, str);
    }
  }
  free(time);
  fclose(f);
}

