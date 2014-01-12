#include <inc/merge_sort.h>
#include <algorithm>

template<typename T, typename C>
void merge_sort<T, C>::divide(size_t s, size_t e)
{
   if ( s + 1 >= e)
       return; 
   size_t m = (s+e)/2;
   divide(s, m);
   divide(m, e);
   merge(s, e);
}
template<typename T, typename C>
void merge_sort<T,C>::merge(size_t s, size_t e)
{
    C c;
    size_t m = (s+e)/2, i = s, j = m; 
    size_t k = 0;
    while(i < m && j < e)
        h[k++] = c(a[j], a[i])? a[i++]: a[j++];
    while(i < m)
        h[k++] = a[i++];  
    while(j < e)
        h[k++] = a[j++];
    std::copy(h, h + e - s, a + s);
}
template<typename T, typename C>
void merge_sort<T,C>::do_work(void)
{
   divide(0, sz);
}
