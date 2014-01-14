//package com.charlesq.java.visitorpattern;
import java.util.Comparator;
import java.util.Random;
import java.lang.Object;
/* abstract visitor interface in visitor pattern */
/* In usage, test array is supplied by concrete visitor,
   it is reasonable for visitor to provide comparison
   methods.

   define it as a class rather an interface because 
   we need to put some utility method common to all
   concrete visitor classes.

 */ 
public abstract class  Visitor<T extends Comparable<T>> 
{
    T [] a;
    /* abstract visit methods for concrete elements */
    public abstract void visit(QuickSort<T > qs);
    public abstract void visit(BubbleSort<T> bs);
    public abstract void visit(InsertSort<T> is);
    public abstract void visit(HeapSort<T> hs);
    public abstract void visit(MergeSort<T> ms);
    public abstract void visit(Algorithms<T> al);

    final void shuffleArray()
    {
        Random r = new Random();
        for (int i = 1; i < a.length; ++i)
        {
            int j = r.nextInt(i+1); 
            if (i == j)
                continue;
            T t = a[i];
            a[i] = a[j];
            a[j] = t;
        } 
    }
    abstract void printElement(int i);
    final public void printArray()
    {
        System.out.println();
        for (int i = 0; i < a.length; ++i)
        {
            printElement(i);
            if((i+1) % 10 == 0)
                System.out.println();
        }
        System.out.println();
    }
   
}
