#include <stdio.h>

// Compiled using gcc compiler flags -m32 -static -fno-stack-protector -mpreferred-stack-boundary=2 for 32 bit
// Compiled using gcc compiler flags -static -fno-stack-protector for 64 bit

int main() {
   char* buf[128];
   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   printf("Show we what you ROP!\n");
   fgets(buf, 2048, stdin);
   printf("Let's see if you can ROP!\n");
   return 0;
}

