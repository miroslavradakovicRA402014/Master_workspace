// Example code for LED blinking on RPI2 platform as Bare Metal application

// Base address of GPIO peripheral 
#define GPIO_BASE_ADDR  0x3F200000UL
// Offset to function selection of GPIO pin 
#define GPIO_GPFSEL     4UL
#define GPIO_GPFBIT     21UL
// Offset to output clear 0 and 1
#define GPIO_GPCLR0     10UL     
#define GPIO_GPCLR1     11UL
// Offset to output set 0 and 1
#define GPIO_GPSET0     7UL
#define GPIO_GPSET1     8UL
// LED bit 
#define GPIO_LED_BIT    15UL

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
    *(gpio_periph + GPIO_GPFSEL) |= 1 << GPIO_GPFBIT;  
    // Blink LED diode loop
    while (1)
    {
        // Wait for a time
        for (time = 0; time < 500000; time++);
        // Turn on LED diode
        *(gpio_periph + GPIO_GPCLR1) = 1 << GPIO_LED_BIT;  
        // Wait for a time again
        for (time = 0; time < 500000; time++);
        // Then turn off LED diode
        *(gpio_periph + GPIO_GPSET1) = 1 << GPIO_LED_BIT;       
    }
}
