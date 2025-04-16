#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

#ifndef HAVE_STRMID
int strmid(const char *source, char *dest, int pos, int len);
#endif

#endif
