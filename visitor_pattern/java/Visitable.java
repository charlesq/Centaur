//package com.charlesq.java.visitorpattern;
import java.util.Comparator;
import java.lang.Object;
public interface  Visitable<T extends Comparable<T>> 
{
    /* accept method in visitor pattern */
    abstract void accept(Visitor<T> v);
}
