#include <stdio.h>
#include <string.h>

enum http_verbs {
  GET = 0,
  HEAD,
  POST,
  PUT,
  DELETE,
  TRACE,
  OPTIONS,
  CONNECT,
  PATCH
};

enum http_versions {
  ZERO_POINT_NINE = 0,
  ONE_POINT_ZERO,
  ONE_POINT_ONE
};
//request line <CR><LF> or /r/n
//headers <CR><LF> or /r/n, host is required for request
//empty line <CR><LF> or /r/n
//optional message body

int main() {
  enum http_verbs request_verb = HEAD;
  enum http_versions request_version = ONE_POINT_ONE;
  char *request_resource; /* /index.html */
  //host = char[]
  
  char *token, *line, *request, *tofree, *tofreeline, *tofreetoken;
  request = strdup("GET /index.html HTTP/1.1\r\nHost: www.example.com");
  //request = strdup("testingrestingbesting");
  
  /*
  if(request != NULL) {
    tofree = request;
    while((token = strsep(&request, "\r\n")) != NULL) {
      if (*token != '\0') {
        printf("%s\n", token);
      }
    }
    free(tofree);
  }
  */
  //compare with strtok_r
  if(request != NULL) {
    tofreeline = request;
    while((line = strsep(&request, "\r\n")) != NULL) {
      if (*line != '\0') {  //returns matches as '\0'
        printf("%s\n", line);
        
        //tofreetoken = line;
        while((token = strsep(&line, " ")) != NULL) {
          if (*token != '\0') {
            printf("%s\n", token);
          }
        }
        //free(tofreetoken);
        
      }
    }
    free(tofreeline);
  }
  printf("%s\n", request);
  
}