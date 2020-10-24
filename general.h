#ifndef __GENERAL_H
#define __GENERAL_H

#ifdef __cplusplus
extern "C" {
#endif

// Find size of an arbitrary type
#define num(x)      (sizeof(x) / sizeof(*x))

int general_gcd(int, int);
double general_sqrt(int);
  
#ifdef __cplusplus
}
#endif

#endif // __GENERAL_H
