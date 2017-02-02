#ifndef MYARRAY /* Header Guard         */
#define MYARRAY /* prevents recompiling */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/* typdefs for compact struct */
typedef void (ctor_f)(void *dst, const void *src);
typedef void (dtor_f)(void *elt);
typedef void (init_f)(void *elt);

/* what needs to be completed in product.c */
// controlBlock
typedef struct {
  size_t sz;
  init_f *init;
  ctor_f *copy;
  dtor_f *dtor;
} controlBlock;

// myArray
typedef struct {
  unsigned index;       /* index of next available slot */
  unsigned capacity;    /* current number of available slots */
  controlBlock cb;      /* see above description */
  char *d;              /* data slots */
} myArray;


/* function prototypes */
myArray* newMyArray(controlBlock *cb);
void freeMyArray(myArray *a);
void reserveMyArray(myArray *a,int by);
void pushMyArray(myArray *a,void *p);
void popMyArray(myArray *a);
void extendMyArray(myArray *a);
unsigned lengthOfMyArray(myArray *a);
unsigned capacityOfMyArray(myArray *a);
void* elementFromIndexOfMyArray(myArray *a,int j);
void* _elementFromIndexOfMyArray(myArray *a,int j);
void insertAtMyArray(myArray *a,void *p,unsigned j);
void resizeMyArray(myArray *dst,int num);
void eraseMyArray(myArray *a,int pos,int len);
void clearMyArray(myArray *a);
void* frontOfMyArray(myArray *a);
void* nextElementOfMyArray(myArray *a,void *e);
void* prevElementOfMyArray(myArray *a,void *e);
void* backOfMyArray(myArray *a);
unsigned indexOfElementInMyArray(myArray *a,void* e);


#endif /* MYARRAY */
