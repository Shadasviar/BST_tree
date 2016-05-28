#include <stdio.h>
#pragma once

typedef float t_type;

struct complex_t{
  t_type a, b;
};

typedef struct complex_t complex_t;

complex_t set_complex(int, int);
void print_complex(complex_t);
complex_t add_complex(complex_t, complex_t);
complex_t sub_complex(complex_t, complex_t);
complex_t mul_complex(complex_t, complex_t);
complex_t div_complex(complex_t, complex_t);

