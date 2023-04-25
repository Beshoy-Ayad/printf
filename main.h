#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


int _printf(const char *format, ...);

int _printLettler(char c);
int _printWord(char *s);
int _printInt(int n);

#endif
