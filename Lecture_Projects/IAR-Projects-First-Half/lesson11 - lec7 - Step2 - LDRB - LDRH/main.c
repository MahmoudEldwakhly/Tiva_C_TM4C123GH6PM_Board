#include <stdint.h>

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

uint8_t  u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int main() {

    u8a  = sizeof(u8a);
    u16c = sizeof(uint16_t);
    u32e = sizeof(uint32_t);
    
    u8a  = 0xa1U;
    u16c = 0xc1c2U;
    u32e = 0xe1e2e3e4U;
    
    u8b  = u8a;
    u16d = u16c;
    u32f = u32e;
}
