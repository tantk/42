#include <stdio.h>
#include <stdbool.h>

void print_hex(unsigned int value) {
    // Define hexadecimal characters
    char hex_chars[] = "0123456789abcdef";

    // Check if value is zero
    if (value == 0) {
        putchar('0');
        return;
    }

    char buffer[9];  // Assuming 32-bit unsigned int
    int pos = 0;

    // Convert value to hexadecimal
    while (value) {
        buffer[pos++] = hex_chars[value & 0xF];  // Take the last 4 bits
        value >>= 4;  // Shift right by 4 bits
    }

    // Print the hexadecimal value in reverse order
    while (--pos >= 0) {
        putchar(buffer[pos]);
    }
}

int main() {
    int num = 128;
    print_hex(num);
    putchar('\n');
	printf("printf %X\n",num);
    return 0;
}
