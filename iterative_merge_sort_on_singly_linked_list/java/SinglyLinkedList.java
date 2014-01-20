import java.lang.Iterable;
import java.util.Iterator;
import java.util.Collection;
import java.lang.Number;
import java.lang.UnsupportedOperationException;
import java.util.NoSuchElementException;

public class SinglyLinkedList<T extends Number> implements Collection <T>
{
    private Node<T> head; 
    private int size;
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
            return node != null;
        }
        @Override
        public T next()
        {
            if (node == null)
                throw new NoSuchElementException();
            T e = node.value();
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
       if (head != null)
            nd.setNext(head);
       head = nd;
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
        head = null;
        size = 0;
    }
    @Override
    public boolean equals(Object o)
    {
        return o.equals(this); 
    }
     
}
