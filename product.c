#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "myarray.h" // interface for the set of dynamic array functionss


typedef struct {


  char* name;
  float price;
  bool in_stock;


} product_t;

/* set the in_stock property to true */
void product_init(void *src) {


// when newarray is called

 product_t* scr = malloc( sizeof( product_t ) );
 scr->name = NULL;
 scr->price = 0.00;
 scr->in_stock = true;



}

void product_copy(void *_dst, const void *_src) {



  //when push or insertAtMyArray is called

 _dst = realloc( (void*)_src   ,  sizeof( product_t*)  );
  free( (void*)_src);
  // _dst->name = _src;
  // _dst->price = _src;
  // _dst->in_stock = _src;




  //product_t *_dst = ( _src )malloc( sizeof( ) );
  //name = ( char* )realloc(&_  )
}

void product_dtor(void *_elt) {


  //when free or pop is called

  free( _elt );




}

controlBlock product_cb = { /*complete*/ };

//controlBlock product_cb = { 3 };


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
