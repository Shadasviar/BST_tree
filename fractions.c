/*
 * fractions.c
 * Copyright (C) Uladzislau Harbuz 2016 
 *  
 * This file is part of BST_tree.
 * 
 * BST_tree is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BST_tree is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "fractions.h"
#include <stdio.h>
#include <stdlib.h>

int nwd(int a, int b){
  if(b == 0){
    return a;
  }
  else{
    return nwd(b, a % b);
  }
}


fraction make_fraction(t_type a, t_type b){
  if(b == 0){
    puts("Error: division by zero");
    exit(1);
  }
	return (fraction){a, b};
}


fraction fr_sum(fraction a, fraction b){
	t_type n = (a.denominator* b.denominator) / (t_type)nwd(a.denominator, b.denominator);
	fraction tmp_a, tmp_b;
	tmp_a = fr_mult(a, make_fraction(n/a.denominator, n/a.denominator));
	tmp_b = fr_mult(b, make_fraction(n/b.denominator, n/b.denominator));
	tmp_a.numerator += tmp_b.numerator;
	return tmp_a;
}


fraction fr_sub(fraction a, fraction b){
	t_type n = (a.denominator* b.denominator) / (t_type)nwd(a.denominator, b.denominator);
	fraction tmp_a, tmp_b;
	tmp_a = fr_mult(a, make_fraction(n/a.denominator, n/a.denominator));
	tmp_b = fr_mult(b, make_fraction(n/b.denominator, n/b.denominator));
	tmp_a.numerator -= tmp_b.numerator;
	return tmp_a;
}


fraction fr_mult(fraction a, fraction b){
	return (fraction ) {a.numerator * b.numerator,
	                              a.denominator * b.denominator};
}


fraction fr_divide(fraction a, fraction b){
	return (fraction ){a.numerator * b.denominator,
	                              a.denominator * b.numerator};
}


double fraction_to_double(fraction fr){
	return ((double)fr.numerator) / fr.denominator;
}


void fr_print(fraction fr){
	printf("%d/%d ", fr.numerator, fr.denominator);
}

