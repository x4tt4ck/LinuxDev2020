#ifndef NAMEGEN_H
#define NAMEGEN_H
 
#define NAMEGEN_MAX_DEPTH  32 /* Cannot exceed bits in a long */
 
/* Return codes */
#define NAMEGEN_SUCCESS    0
#define NAMEGEN_TRUNCATED  1  /* Output was truncated */
#define NAMEGEN_INVALID    2  /* Pattern is invalid */
#define NAMEGEN_TOO_DEEP   3  /* Pattern exceeds maximum nesting depth */

int namegen(char *dst, unsigned long len, const char *pattern, unsigned long *seed);

#endif
