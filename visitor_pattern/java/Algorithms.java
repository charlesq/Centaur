//package com.charles.java.visitorpattern;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class Algorithms <T extends Comparable<T>> implements Visitable<T>
{
    ArrayList<Visitable<T>> elements = new ArrayList<Visitable<T>>(); 
    public Algorithms ()
    {
        elements.add(new MergeSort<T>());
        elements.add(new HeapSort<T>());
        elements.add(new BubbleSort<T>());
        elements.add(new InsertSort<T>());
    }
    @Override
    public void accept(Visitor<T> v) 
    {
        Iterator<Visitable<T>> it = elements.iterator();
        while(it.hasNext())
            it.next().accept(v);
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
