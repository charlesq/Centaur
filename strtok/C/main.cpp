#include <stddef.h>
#include <iostream>
namespace myns
{
    char *strtok_r(char *str, const char *delim, char **saveptr)
    {
       char *s = str;
       if (s ==NULL && (s = *saveptr) == NULL)
           return NULL; 
       char *tok = s;
       while (*s != '\0')
       {
           const char *dem = delim;
           while(*dem != '\0')
           {
               if (*dem != *s)
                   ++dem;
               else
                  break;
             
           }
           if (*dem == '\0')
           {
               ++s;
               continue;
           }
           /* found a delimiter */
           /* if it is not the fist letter of token string, accept it */
           if (tok != s)
           {
               *s++ = '\0';
               *saveptr = s; 
               return tok;
           }
          /* otherwise skip it, continue parsing */
           ++tok;
           s++;
       }
       /* reached end of target string */ 
       *saveptr = NULL;
       return tok; 
    }
}


int main()
{
  while(true)
  {
     char del[100];
     char strr[200];
     char *saveptr;
     std::cout << "Input the taret string: ";
     std::cin >> strr; 
     std::cout << "Input the delimeter string: ";
     std::cin >> del;
     std::cout << "Token strings: " << std::endl;
     char *str = strr;
     while(true)
     {
         char *tok = myns::strtok_r(str, del, &saveptr);
         if (tok == NULL)
             break;
         std::cout << tok << " ";
         str = NULL;
     }
     std::cout << "\nExit (Y/N)?";
     std::cin >> *strr;
     if (*strr == 'Y' || *strr == 'y')
         break;
     std::cout << std::endl;
    
  }  
  return 0;
}
