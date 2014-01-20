
import java.lang.Comparable;
import java.lang.Iterable;
import java.lang.Number;
public class Node<T extends Comparable<T> > 
{
     private  T value;
     private Node<T> next;

     public Node(T value, Node<T> n)
     {
         this.value = value;
         this.next = n;
     }
     public Node(T value)
     {
         this.value = value;
     }
     public T value()
     {
         return value;
     }
     public void  setNext(Node<T> n)
     {
         next = n;
     }
     public void setValue(T value)
     {
         this.value = value;
     }
     public Node<T> next()
     {
         return next;
     }
     @Override
     public String toString()
     {
         return "Node with value of " + value.toString()+ " " ; 
     }
     
}
