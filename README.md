# Decimal-library

Данная библиотека дает возможность работать с типом данных decimal при разработки на С:

1. Содержит функции перевода из float и int в decimal, и функции обратного перевода из decimal в int и float.
2. Имеются функции для проведения основных математических операций (сложение, вычитаение, деление, умножение) между двумя числами decimal.

В makefile представленны все основные цели по сборке (all, test, gcov_report, leaks, valgrind, clean). 

Для тестирования библиотеки можно воспользоавться целью test. 

Для анализа степени покрытия тестами можно воспользоваться целью gcov_report которая создать html страницу где можно оценить степень покрятия тестами. 

Проверить на утечки в памяти можно с помощью утилит leaks и valgrind, которые запускаются соответсвующими целями.
