#include <inc/radix_sort.h>
#include <algorithm>
template<typename T, typename C>
void radix_sort<T, C>::do_work(void)
{
    size_t radix = 1;
    bool halt = false; 
    size_t v =0;
    while(true)  
    {
       halt = true;
       std::fill(acc, acc + BASE, v); 
       /* applying counting sort */
       for (size_t i = 0; i < sz; ++i)
       {
           int c = a[i] / radix % BASE;
           if (halt && c != 0)
               halt = false;
           ++acc[c];
       }
       if (halt)
           break;
       for (size_t i = 1; i < BASE; ++i)
           acc[i] += acc[i -1];      
       for (size_t i = 0; i < sz; ++i)
           h[--acc[a[i] / radix % BASE]] = a[i]; 
       std::copy(h, h + sz, a);
       /* move to the next radix */
       radix  *= BASE;
    }
    
} 
