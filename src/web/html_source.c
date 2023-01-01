#include <web/html_source.h>


static size_t 
write_data (void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}
static const temp_t
download_to_tmpfile (const char *url)
{
  temp_t temp = init_tempfile(24);
  CURL *curl = curl_easy_init();
  if (!curl) {
    log_err("crystal.log", true, FF(), "Could not initialize curl!");
  }
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fopen("test", "wb")); // We are not closing it, because we have a cleanup function in tempfile to do it for us.

  // Now we try to download the file.
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    curl_easy_cleanup(curl);
    log_err("crystal.log", true, FF(), "Failed to download the file.");
  }
 // return temp;
}

static const char *
read_file_to_var (const char *path)
{
  return tmp_to_var(path);
}

const char *
retrive_html (const char *url)
{
  const temp_t tmp = download_to_tmpfile(url);
  const char *result = read_file_to_var(tmp.path);
  if (result != NULL) {
    return result;
  }
  log_debug("crystal.log", true, FF(), "Failed to retrieve html.");
  return NULL;
}
