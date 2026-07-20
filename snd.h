/* SPDX-License-Identifier: CC0-1.0 */

/*
   This work is dedicated to the public domain under CC0 1.0.
   You may use, modify, distribute, and sell this file without restriction.
   See the LICENSE file or <https://creativecommons.org/publicdomain/zero/1.0/>
   for the full legal text.
 */

/*
   Add "#define SND_IMPLEMENTATION" before you include this file in *one* C
   file to create the implementation.

It should look like this:

#define SND_IMPLEMENTATION
#include "snd.h"

 */

#ifndef _INCLUDE_SND_H
#define _INCLUDE_SND_H

#ifndef _SND_DEF
#define _SND_DEF

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// true = str is empty
bool snd_str_is_empty(const char *s);

// note: returns allocated string that must be freed
// returns NULL on error
char *snd_read_entire_file(FILE *f);

// true if a and b are different at a memory level
bool snd_are_diff(const void *a, const void *b);

void snd_str_to_lowercase(char *s, size_t len);

// trims start/end spaces of a str in place
// inspired by the .trim() method of Rust
void snd_trim_str(char *str);

#endif // _SND_DEF

#ifdef SND_IMPLEMENTATION

// internal
size_t _snd_get_fsize(FILE **f) {
  fseek(*f, 0, SEEK_END);
  long fsize = ftell(*f);
  fseek(*f, 0, SEEK_SET);
  return fsize;
}

char *snd_read_entire_file(FILE *f) {
  size_t fsize = _snd_get_fsize(&f);
  char *content = malloc(fsize + 1);
  int r;
  r = fread(content, fsize, 1, f);
  if (r == 0) {
    return NULL;
  }
  r = fclose(f);
  if (r != 0) {
    return NULL;
  }
  content[fsize] = 0;
  return content;
}

bool snd_str_is_empty(const char *s) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (isalpha(s[i])) {
      return false;
    }
  }
  return true;
}

bool snd_are_diff(const void *a, const void *b) {
  return memcmp(a, b, sizeof *b) != 0;
}

void snd_str_to_lowercase(char *s, size_t len) {
  for (size_t i = 0; i < len; i++)
    s[i] = tolower(s[i]);
}

void snd_trim_str(char *str) {
  char *start = str;
  while (*start && isspace((unsigned char)*start)) {
    start++;
  }
  if (*start == '\0') {
    str[0] = '\0';
    return;
  }
  char *end = start + strlen(start) - 1;
  while (end > start && isspace((unsigned char)*end)) {
    end--;
  }
  size_t len = (end - start) + 1;
  memmove(str, start, len);
  str[len] = '\0';
}

#endif // SND_IMPLEMENTATION
#endif // _INCLUDE_SND_H
