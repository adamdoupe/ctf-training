#include <stdio.h>

// Compiled using gcc compiler flags -m32 -static -fno-stack-protector -mpreferred-stack-boundary=2

void pivot_me()
{
   int buf[1];
   int i;
   int v;
   scanf("%d\n", &i);
   scanf("%d\n", &v);
   i[buf] = v;
}

int main()
{
   char buf[1024];
   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   printf("You can pivot a couch, but can you pivot a ROP?\n");

   fgets(buf, 1024, stdin);

   pivot_me();

   return 0;
}
