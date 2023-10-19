#include "s21_decimal.h"

void s21_copy_decimal(s21_decimal *d1, s21_decimal d2) {
  for (int i = 127; i >= 0; i--) {
    s21_set_bit_on_index(d1, i, s21_get_bit_on_index(d2, i));
  }
}

void s21_normalize_scale_upper(s21_decimal *d, int norm) {
  s21_decimal _norm = {0};
  s21_decimal _res = {0};
  s21_from_float_to_decimal(pow(10, norm), &_norm);
  s21_mul(*d, _norm, &_res);
  s21_set_mantissa(&_res, s21_get_mantissa(*d) + norm);
  s21_copy_decimal(d, _res);
}

void s21_normalize(s21_decimal *d1, s21_decimal *d2) {
  int norm = s21_get_mantissa(*d1) - s21_get_mantissa(*d2);
  if (norm > 0) {
    s21_normalize_scale_upper(d2, norm);
  } else if (norm < 0) {
    s21_normalize_scale_upper(d1, -norm);
  }
}