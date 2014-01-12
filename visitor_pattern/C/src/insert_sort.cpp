#include <inc/insert_sort.h>
template <typename T, typename C>
void insert_sort<T,C>::do_work(void)
{
    C c;
    for (size_t i = 1; i < sz; ++i)
        for (size_t j = 0; j < i; ++j)
        {
            if (c(a[j+1], a[j]))
                std::swap(a[j+1], a[j]);
        }
}
