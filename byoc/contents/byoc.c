#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
// Compiled using gcc compiler flags -m32 -fno-stack-protector -mpreferred-stack-boundary=2 -Wno-format -D_FORTIFY_SOURCE=0





void foo(char* buf, unsigned int num_void)
{
   int i;
   for (i = 0; i < num_void; i++)
   {
	  syscall(SYS_write, 1, buf+i, 1);
   }
}

void bar(char* buf, unsigned int len)
{
   int i;
   for (i = 0; i < len; i++)
   {
	  syscall(SYS_read, 0, buf+i, 1);
	  if (*(buf+i) == '\n')
	  {
		 *(buf+i) = '\0';
		 return;
	  }
   }
}

void print_menu()
{
   foo("Please select an option\n", strlen("Please select an option\n"));
   foo("1. Say Hello\n", strlen("1. Say Hello\n"));
   foo("2. Tell me what to say\n", strlen("2. Tell me what to say\n"));
   foo("3. Bye\n", strlen("3. Bye\n"));
   foo("\n", 1);
}

int get_choice()
{
   char buf[2];
   int to_return = 3;

   bar(buf, 2);
   if (*buf == '1')
   {
	  to_return = 1;
   }
   else if (*buf == '2')
   {
	  to_return = 2;
   }
   
   return to_return;
}

void say_hello()
{
   foo("Hello!\n", strlen("Hello!\n"));
}

void tell_me_what_to_say()
{
   char buf[256];

   bar(buf, 1024);

   printf("%s", buf);
}

void main_loop()
{
   int done = 0;
   while (!done)
   {
	  int choice;
	  print_menu();
	  choice = get_choice();
	  if (choice == 1)
	  {
		 say_hello();
	  }
	  else if (choice == 2)
	  {
		 tell_me_what_to_say();
	  }
	  else if (choice == 3)
	  {
		 done = 1;
	  }
   }
}

int main()
{
   char buf[256];

   setbuf(stdin, NULL);
   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

   main_loop();

   return 0;   
}
