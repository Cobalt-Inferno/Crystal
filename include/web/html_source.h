#ifndef HTML_SOURCE_H
#define HTML_SOURCE_H
#ifdef __cplusplus
extern "C" {
#endif 

#include <curl/curl.h>
#include <stdio.h>
#include <malloc/malloc_wrapper.h>
#include <util/tempfile/tempfile.h>


const char *retrive_html (const char *url);

#ifdef __cplusplus
}
#endif // CPLUSPLUS
#endif
