#include <inc/bubble_sort.h>

template <typename T, typename C>
void bubble_sort<T,C>::do_work(void)
{
    C c;
    for (size_t j = sz; j != 0; --j)
        for (size_t i = 0; i + 1< j; ++i)
        {
            if (c(a[i+1], a[i]))
                std::swap(a[i], a[i+1]);
        }
}
