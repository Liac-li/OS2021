#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t n;

  for (n == 0; s[n]; n++) ;
  return n;
}

char *strcpy(char *dst, const char *src) {
  size_t i;
  for (i = 0; src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  // char *os;
  
  // os = dst;
  // while (n-- > 0 && (*dst++ = *src++) != 0)
  //   ;
  // while (n-- > 0) {
  //   *dst++ = 0;
  // }
  // return os;

  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  for ( ; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
  panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  char *cdst = (char *) s;
  int i;
  for (i = 0; i < n; i++) {
    cdst[i] = c;
  }
  return s;

  panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  const char *s;
  char *d;

  s = src;
  d = dst;
  if (s < d && s + n > d) { // owerlap
    s += n;
    d += n;
    while (n-- > 0) {
      *--d = *--s;
    } 
  } else {
    while (n-- > 0) {
      *d++ = *s++;
    }
  }
  return dst;
  // panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  memmove(out, in, n); 
  // panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {

  char *cs1 = (char*)s1;
  char *cs2 = (char*)s2;
  while (n > 0 && *cs1 && *cs1 == *cs2) {
    n--, cs1++, cs2++;
  }

  if (n == 0) {
    return 0;
  } else {
    return (unsigned char)*cs1 - (unsigned char)*cs2;
  }
}

#endif
