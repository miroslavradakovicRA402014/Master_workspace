// Example code for LED blinking on RPI2 and RPI3 platform as Bare Metal application

// Base address of GPIO peripheral
#define GPIO_BASE_ADDR  0x3F200000UL
// Offset to function selection of GPIO pin
#define GPIO_GPFSEL1    1UL
#define GPIO_GPFSEL4    4UL
// Offset to output clear 0 and 1
#define GPIO_GPCLR0     10UL
#define GPIO_GPCLR1     11UL
// Offset to output set 0 and 1
#define GPIO_GPSET0     7UL
#define GPIO_GPSET1     8UL

#if defined(RPI3)
// LED bit
#define GPIO_LED_BIT    16UL
// LED GPFBIT
#define GPIO_GPFBIT     18UL
// SEL register
#define GPIO_SEL        GPIO_GPFSEL1
// SEL register
#define GPIO_GPF        GPIO_GPFBIT
// LED register
#define GPIO_LED        GPIO_LED_BIT
// CLR register
#define GPIO_CLR        GPIO_GPCLR0
// SET register
#define GPIO_SET        GPIO_GPSET0

#else // RPI2
// LED bit
#define GPIO_LED_BIT    15UL
// LED GPFBIT
#define GPIO_GPFBIT     21UL
// GPIOSEL register
#define GPIO_SEL        GPIO_GPFSEL4
// SEL register
#define GPIO_GPF        GPIO_GPFBIT
// LED register
#define GPIO_LED        GPIO_LED_BIT
// CLR register
#define GPIO_CLR        GPIO_GPCLR1
// SET register
#define GPIO_SET        GPIO_GPSET1

#endif

// GPIO register
volatile unsigned long* gpio_periph;
// Time counter
volatile unsigned int time;

int main(void) __attribute((naked));
int main(void)
{
    // Pointer to GPIO regs
    gpio_periph = (unsigned long*) GPIO_BASE_ADDR;
    // Select function on GPIO
    *(gpio_periph + GPIO_SEL) |= 1 << GPIO_GPF;
    // Blink LED diode loop
    while (1)
    {
        // Wait for a time
        for (time = 0; time < 500000; time++);
        // Turn on LED diode
        *(gpio_periph + GPIO_CLR) = 1 << GPIO_LED;
        // Wait for a time again
        for (time = 0; time < 500000; time++);
        // Then turn off LED diode
        *(gpio_periph + GPIO_SET) = 1 << GPIO_LED;
    }
}
