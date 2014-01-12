#include <inc/algorithms.h>
#include <inc/int_visitor.h>
#include <inc/pair_visitor.h>

int main()
{
    algorithms<int, std::less<int>> int_client;
    algorithms<paired, paired_compare> pair_client;
    int_visitor iv(20);
    pair_visitor pv(20);
    std::cout <<"-------------------"<< std::endl;
    std::cout <<"-------------------"<<std::endl;
    std::cout <<" int_visitor visiting algorithm elements " << std::endl;
    int_client.accept(&iv);
    int_client.add_radix_sort();
    std::cout <<"\n-------------------"<< std::endl;
    std::cout <<"-------------------"<<std::endl;
    std::cout <<" pair_visitor visiting algorithm elements " << std::endl;  
    pair_client.accept(&pv);

    return 0;
}

