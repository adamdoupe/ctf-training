#include <stdio.h>

// Compiled using gcc compiler flags -m32 -static -fno-stack-protector -mpreferred-stack-boundary=2 -Wno-format -D_FORTIFY_SOURCE=0

void pivot_me()
{
   char str[128];

   printf("What's your name?\n");
   fgets(str, 128, stdin);

   printf("Why hello\n");
   printf(str);
}

int main()
{
   char buf[1024];

   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   printf("How well can you format your pivots?\n");

   printf("Here's a little boost:\n");   
   printf("%x\n", &buf);   

   printf("Gimme that chain!\n");
   fgets(buf, 1024, stdin);

   pivot_me();

   return 0;   
}
