#include <unistd.h>

int main(void) {
    const char* message = "_putchar\n";
    const int length = 9;

    write(1, message, length);
    return 0;
}
