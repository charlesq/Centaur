import java.lang.Iterable;
import java.util.Iterator;
import java.util.Collection;
import java.lang.Number;
import java.lang.UnsupportedOperationException;
import java.util.NoSuchElementException;
import java.lang.Comparable;

public class SinglyLinkedList<T extends Comparable<T>> implements Collection <T>
{
    private Node<T> head; 
    private int size;
    public SinglyLinkedList()
    {
        head = new Node<T>(null);
        size = 0;
    }
    @Override 
    public int size() 
    {
        return size;
    }
    @Override
    public boolean isEmpty()
    {
        return size==0;
    }
    private class Iter implements Iterator<T>
    {
        Node<T> node;
        public Iter(int index)
        {
            node = SinglyLinkedList.this.head;
            while(--index >= 0 && node != null)
               node = node.next(); 
            
        }
        @Override
        public boolean hasNext()
        {
            return node.next() != null;
        }
        @Override
        public T next()
        {
            if (node == null ||  node.next() == null)
                throw new NoSuchElementException();
            T e = node.next().value();
            node = node.next();
            return e;
        }
        @Override
        public void remove() throws UnsupportedOperationException
        {
           throw new UnsupportedOperationException(); 
        }
    }
    @Override
    public Iterator<T> iterator() 
    {
        return new Iter(0);
    }
    //@Override
    public Iterator<T> iterator(int index)
    {
        return new Iter(index);
    }   
    @Override
    public Object [] toArray() throws UnsupportedOperationException
    {
        throw new UnsupportedOperationException();
    }
    @Override
    public <T> T[] toArray(T[] a) throws UnsupportedOperationException
    {
        throw new UnsupportedOperationException();
    } 
    @Override
    public boolean add (T e)
    {
       Node<T> nd = new Node<T> (e);
       ++size;
       
       nd.setNext(head.next());
       head.setNext(nd);
       return true;        
    }
    @Override
    public boolean removeAll(Collection <?> c)
    {
        throw new UnsupportedOperationException();
    } 
    @Override
    public boolean remove(Object o)
    {
        Node<T> n = head;
        while(n != null && n.next() != null)
        {
            if (n.next().value().equals(o))
            {
                n.setNext(n.next().next());
                --size;
                return true;
            }
        }
        return false;
    }
    @Override
    public boolean contains(Object o)
    {
        Node<T> n = head;
        while (n != null)
        {
            if (n.value().equals(o))
                return true;
            n = n.next();
        }
        return false;

    }
    @Override
    public boolean containsAll(Collection<?> c)
    {
        throw new UnsupportedOperationException();
    }
    @Override
    public boolean addAll(Collection<? extends T> c)
    {
        throw new UnsupportedOperationException();
    }
    @Override
    public boolean retainAll(Collection<?> c) 
    {
        throw new UnsupportedOperationException();
    }
    @Override
    public void clear()
    {
        head.setNext(null);
        size = 0;
    }
    @Override
    public boolean equals(Object o)
    {
        return o.equals(this); 
    }
    /* this is a bottom-up approach, it repeatedly sort sublists with length of 2^0, 2^1, ...
        2^i; at each every step, e.g. to sort a sublist of length 2^i, it merges two contiguous
        and sorted sublists of maximal length of 2^(i-1).

        The catch is to identify all the sublists of length 2^(i-1) at each step and merge every 
        consecutive two. 
      
    */  
    public void mergeSort()
    {
         int ssize = 1;   
         Node <T> pre = head;
         while(true)
         {
             
             while (pre != null && pre.next() != null)
             {
                 int _size = ssize >>>1;
                 if (_size == 0)
                     ++_size;
                 Node<T> middle = pre;
                 /* get the middle,i.e. pre to the node of  the second segment */
                 while(middle != null && _size-- != 0)
                      middle = middle.next(); 
                 int _first_seg_size = ssize >>> 1;
                 if (_first_seg_size == 0)
                     ++_first_seg_size;
                 int  _second_seg_size = ssize - _first_seg_size;
                 /* we have a merge to do */ 
                 while (_first_seg_size >0 || _second_seg_size > 0) 
                 {
                     if (middle != null && middle.next() != null &&  _first_seg_size > 0 && _second_seg_size > 0)
                     {
                         if (pre.next().value().compareTo(middle.next().value()) <= 0)
                         {
                             pre = pre.next();
                             --_first_seg_size;
                         } 
                         else
                         {
                             Node<T> T1 = middle.next(); 
                             middle.setNext(middle.next().next());
                             T1.setNext(pre.next());
                             pre.setNext(T1);
                             pre =T1; 
                             --_second_seg_size; 
                         }
                         continue;
                     }
                     _first_seg_size = 0;
                     if (_second_seg_size > 0 && middle != null)
                     {
                        // already sorted, but we need to obtain the last node */
                         --_second_seg_size;
                         middle = middle.next();
                         continue;
                     }
                     break;
                 }
                 /* move to the next length of 2^i segment */
                 pre = middle;
             }
             if (ssize < size())
             {
                 ssize <<= 1;
                 pre = head;
             }
             else
                 break;
         }
    }  
}
