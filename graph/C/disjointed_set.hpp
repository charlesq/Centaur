#ifndef __DISJOINTED_SET_H__
#define __DISJOINTED_SET_H__
#include <stddef.h>
class disjointed_set;
disjointed_set * find_set(const disjointed_set *ds);
void make_union(disjointed_set *ds1, disjointed_set *ds2);
disjointed_set * make_set(unsigned int v);
class disjointed_set
{
    disjointed_set *ancestor;
    const unsigned int v;/* v marks the vertex number for graph applications */
    disjointed_set(unsigned int vt) :v(vt) { ancestor = NULL; };
    friend disjointed_set * make_set(unsigned int v)
    {
        return new disjointed_set(v);
    };
    friend disjointed_set * find_set(const disjointed_set *ds)
    {
        while(ds->ancestor != NULL)
            ds = ds->ancestor;
        return const_cast<disjointed_set *>(ds);
    };
    friend void make_union(disjointed_set *ds1, disjointed_set *ds2)
    {
        disjointed_set *ancestor1 = find_set(ds1), *ancestor2 = find_set(ds2);
        if (ancestor2 != ancestor1)
            ancestor1->ancestor = ancestor2;
    };
};

#endif
