#include <stdio.h>

// Compiled using gcc compiler flags -m32 -static -fno-stack-protector -mpreferred-stack-boundary=2 -Wno-format -D_FORTIFY_SOURCE=0

void sub()
{
   char buf[20];
   fgets(buf, 21, stdin);
   return;
}

int main()
{
   char buf[1024];

   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   printf("I heard tell of a great hacker, who only needed one byte to control eip.\n");
   printf("Mayhaps you are that hacker?\n");

   printf("Chain me:\n");
   fgets(buf, 1024, stdin);

   sub();
   return 0;   
}
