#define __buzz_c

#include "includeAll.h"
#include "buzz.h"

void BuzzCount(uint8_t count) {
    buzzCounter = count; 
}

void Buzz() {
    buzzLastTimer = D_buzzLastTime;
}

//´ò¿ª·äÃùÆ÷
void Buzz_ON() {
		P_buzz=0;
}
