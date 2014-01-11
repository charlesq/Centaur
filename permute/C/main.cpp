/* problem statement: give a character string composed of distinct alpahbits
 * print out all the permutations of the string characters.
 *
 *
 */
 
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;
void permute(char *str, const size_t &size)
{
   static size_t c = 0; /* other than helping with format output,
                            it also tracks the total number of permutations */
   /* accept */
   if (*str == '\0')
   {
     cout << (str - size) << " ";
     if (++c % 10 == 0)
        cout << endl;
     return;
   } 
   /* obtain extensions */
   for (size_t i = 0; i < strlen(str); ++i)
   {
      swap(str[0], str[i]);
      /* recursive call */
      permute(str + 1, size);
      swap(str[0], str[i]);
   } 
}

int main()
{
  char p[10];  
  char s[] = "abc";
  strcpy(p, s);  
  size_t l = strlen(p);
  permute(p, l);
  cout << endl;
  return 0;
}
