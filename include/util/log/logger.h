#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#define __STDC_WANT_LIB_EXT2__ 1
#define FF() __FILE__, __LINE__
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_MSG 5096

void log_err (char *logpath, bool _stdout, char *file, int line, const char *format, ...);
void log_debug (char *logpath, bool _stdout, char *file, int line, const char *format, ...);
void log_info (char *logpath, bool _stdout, char *file, int line, const char *format, ...);

#ifdef __cplusplus
}
#endif
#endif
