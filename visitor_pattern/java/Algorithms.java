//package com.charles.java.visitorpattern;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class Algorithms <T extends Comparable<T>> implements Visitable<T>
{
    
    public void accept(Visitor<T> v) 
    {
        (new QuickSort<T>()).accept(v);
        (new MergeSort<T>()).accept(v);
        (new HeapSort<T>()).accept(v);
        (new BubbleSort<T>()).accept(v);
        (new InsertSort<T>()).accept(v);
        v.visit(this);
    }
    @Override
    public void finalize()
    {
    }
    @Override
    public String toString()
    {
        return "Algorithms";
    }
}
