#include <stdio.h>

// Compiled using gcc -static test.c and gcc -m32 -static test.c

int main() {
   char* buf[256];
   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   printf("Show we what you ROP!\n");
   fgets(buf, 1024, stdin);
   printf("Let's see if you can ROP!\n");
   return 0;
}

