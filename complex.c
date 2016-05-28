#include "complex.h"

complex_t set_complex(int a, int b){
  return (complex_t) {a, b};
}


void print_complex(complex_t in){
  printf("(%.2f + %.2fi) ", in.a, in.b);
}


complex_t add_complex(complex_t a, complex_t b){
  return (complex_t) {a.a + b.a, a.b + b.b};
}


complex_t sub_complex(complex_t a, complex_t b){
  return (complex_t) {a.a - b.a, a.b - b.b};
}


complex_t mul_complex(complex_t a, complex_t b){
  return (complex_t) {(a.a * b.a)-(a.b * b.b), (a.a * b.b) + (b.a * a.b)};
}


complex_t div_complex(complex_t a, complex_t b){
  return (complex_t) {((a.a * b.a) + (a.b * b.b)) / ((b.a*b.a)+(b.b*b.b)),
   ((b.a * a.b) - (a.a * b.b)) / ((b.a*b.a)+(b.b*b.b))};
}


