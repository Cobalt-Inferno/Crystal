#ifndef LOGGER_H
#define LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#define __STDC_WANT_LIB_EXT2__ 1

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_MSG 5096

static inline void log_err (char *logpath, bool _stdout, const char *format, ...);
static inline void log_debug (char *logpath, bool _stdout, const char *format, ...);
static inline void log_info (char *logpath, bool _stdout, const char *format, ...);

#ifdef __cplusplus
}
#endif
#endif
