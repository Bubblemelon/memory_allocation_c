#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "myarray.h" // interface for the set of dynamic array functionss


// product_t properties
typedef struct {
  /* complete */

  char* name;  // this is the only one that needs memory allocation
  float price;
  bool in_stock;

} product_t;



/* set the in_stock property to true | initialise product_t properties*/
void product_init(void *src) {

// Similar to c++ construtor
// when newMyArray is called

/*
* NOTE:
* always do pointer casting when parameter has void*  !!!
*
*/

// Do memory allocation in the copy function


//Pointer casting:
product_t * p = ( product_t* )src;

 p->name = NULL;
 p->price = 0.00;
 p->in_stock = true;


}

void product_copy(void *_dst, const void *_src) {


  // when push or insertAtMyArray is called
  // similar to c++ copy construtor
  // dont free memory in this copy function ; use the dtor to free up memory



// NOTE:
// These are equal !!!
// obj -> price
// (obj*).price


//pointer casting:

product_t *d = ( product_t *)_dst;
product_t *s = ( product_t *)_src;


d->price = s->price; // this just copies over if it is in the stack (not heap)
d->in_stock = d->in_stock; // this is on the stack

/*
*two ways of reallocate memory for a c string  either use "strdup" or "malloc"
* name is on the heap as defined in struct
*/

d->name = strdup( s->name ); //strdup is defined in myarray.h under #include <string.h>

//or

// d->name = ( char* )malloc( sizeof( 1 ) * strlen(s)+1 );  //size of 1 byte & the length of the string ( plus 1 for null terminator)

// !!!!!!!!!!!!!!!!
// DO I STILL NEED TO CAST char* ?!?!?!?!!?!
// http://stackoverflow.com/questions/1350376/function-pointer-as-a-member-of-a-c-struct
// Floating point exception
// !!!!!!!!!!!!!!!!!!!1

}

void product_dtor(void *_elt) {

  //when free or pop is called

  //pointer casting:
  product_t *e = ( product_t *)_elt;

  if( e->name != NULL )
  {
    free( e->name );
  }



}

//function pointers
controlBlock product_cb =
{
  //init_f;
  //ctor
 };




int main() {
  myArray *products;
  product_t product, *p;

  products = newMyArray(&product_cb); //initialise a new array with type controlblock

  product.price = 3.50; product.name = "Crest Toothbrush"; pushMyArray(products, &product); // pushes "product" into the array product(s)
  product.price = 4.25; product.name = "Oral-B Toothbrush"; pushMyArray(products, &product);

  p=NULL; // fornt of element
  while(    (  p = ( product_t* )nextElementOfMyArray( products,p )  )       )
  {
    printf("$%5.2f %s %s\n", p->price, ( p->name ? p->name : "null"), p->in_stock == true ? "in stock" : "out of stock");
  }

  while(  lengthOfMyArray(products) > 1  )
  {
    popMyArray(products);
  }

  p=NULL;
  while( (p=(product_t*)nextElementOfMyArray(products,p))) {
    printf("$%5.2f %s %s\n", p->price, (p->name ? p->name : "null"), p->in_stock == true ? "in stock" : "out of stock");
  }

  freeMyArray(products);
  return 0;
}
