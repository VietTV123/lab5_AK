#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char **argv){
  int d;
  int a = 0, b = 0, c = 0;


  while (true){
      static struct option long_options[] =
              {
                {"arg_a",        no_argument, nullptr, 'a'},
                {"arg_b",     no_argument, nullptr, 'b'},
                {"arg_c",        no_argument, nullptr, 'c'},

                {nullptr, 0, nullptr, 0}
              };
      int opt_index = 0;

      d = getopt_long (argc, argv, "abc", long_options, &opt_index);

      if (d == -1) break;

      switch (d){
          case 'a':
              if (a == 0) {
                  printf("Argument A");
                  a = 1;
              }
              break;

          case 'b':
              if(b == 0){
                  printf("Argument B");
                  b = 1;
              }
              break;

          case 'c':
              if (c == 0) {
                  printf("Argument C");
                  c = 1;
              }
              break;

          case '?':
              break;

          default:
              break;
      }
  }

  if (optind < argc){
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
          printf ("%s ", argv[optind++]);
      putchar ('\n');
  }
  exit (0);
}
