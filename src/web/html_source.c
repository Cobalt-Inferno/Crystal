#include "util/tempfile.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <web/html_source.h>


static size_t 
write_data (void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}
static const temp_t *
download_to_tmpfile (const char *url)
{
  temp_t *temp = init_tempfile(24);
  CURL *curl = curl_easy_init();
  if (!curl) {
    return NULL;
  }
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fopen(temp->path, "wb")); // We are not closing it, because we have a cleanup function in tempfile to do it for us.

  // Now we try to download the file.
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    curl_easy_cleanup(curl);
    return NULL;
  }
  return temp;
}

static const char *
read_file_to_var (const char *path)
{
  FILE *fp = fopen(path, 'r');

}
