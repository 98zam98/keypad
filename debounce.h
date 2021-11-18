
#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include "hardware.h"

//char debounce_init();

char debounce_init(char* d,char* p,char di);

char debounce_pushed(char input_PINC,char d);

#endif /* DEBOUNCE_H_ */