/*
 * fractions.h
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

#pragma once

typedef int t_type;

typedef struct{
	t_type numerator;
	t_type denominator;
} fraction;

fraction make_fraction(t_type, t_type);
fraction fr_sum(fraction, fraction);
fraction fr_sub(fraction, fraction);
fraction fr_mult(fraction, fraction);
fraction fr_divide(fraction, fraction);

double fraction_to_double(fraction);
void fr_print(fraction);
