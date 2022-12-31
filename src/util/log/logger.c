#include <util/log/logger.h>

static char *
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


void 
log_info (char *logpath, bool _stdout, char *_file, int line, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %d) -- INFO: %s\n", time, _file, line, str);
      fprintf(f, "%s -- %s (LINE: %d) -- INFO: %s\n", time, _file, line, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %d) -- INFO: %s\n", time, _file, line, str);
    }
  }
  free(time);
  fclose(f);
}
void 
log_debug (char *logpath, bool _stdout, char *_file, int line, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %d) -- DEBUG: %s\n", time, _file, line, str);
      fprintf(f, "%s -- %s (LINE: %d) -- DEBUG: %s\n", time, _file, line, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %d) -- DEBUG: %s\n", time, _file, line, str);
    }
  }
  free(time);
  fclose(f);
}
void 
log_err (char *logpath, bool _stdout, char *_file, int line, const char *format, ...)
{
  char str[MAX_MSG];
  FILE *f = fopen(logpath, "a");
  char *time = omit_last_end(fetch_time());
  if (f) {
    va_list args;
    va_start(args, format);
    vsnprintf(str, MAX_MSG, format, args);
    va_end(args);
    if (_stdout) {
      printf("%s -- %s (LINE: %d) -- ERROR: %s\n", time, _file, line, str);
      fprintf(f, "%s -- %s (LINE: %d) -- ERROR: %s\n", time, _file, line, str);
    } else {
      fprintf(f, "%s -- %s (LINE: %d) -- ERROR: %s\n", time, _file, line, str);
    }
  }
  free(time);
  fclose(f);
}

