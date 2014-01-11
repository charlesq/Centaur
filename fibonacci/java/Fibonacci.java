import java.util.ArrayList;
public class Fibonacci 
{
   private static int a = 0, b = 1, tracker = 0;
   private static ArrayList<Integer> seq = new ArrayList<Integer>();
   public static int getNext()
   {
      if (tracker == 0)
      {
          ++tracker; 
          return 0;
      } 
      if (tracker == 1)
      {
          ++tracker;
          return b;
      }
      int next = a + b;
      a = b;
      b = next;
      return next;
   } 
   public static int getElement(int index)
   {
      while(seq.size() < index+1)
      {
          if (seq.size() == 0)
          {
              seq.add(0);
              continue;
          }
          if (seq.size() == 1)
          {
              seq.add(1); 
              continue;
          }
          seq.add(seq.get(seq.size() -2) + seq.get(seq.size()-1));
      }
      return seq.get(index);
   } 
   /* test driver */
   public static void main(String [] args)
   {
      int index = 0;
      while(index < 40)
      {
         System.out.format("%10d ", Fibonacci.getNext());
          if (++index % 10 == 0)
              System.out.println();
      }
      System.out.println();
      index = 0;
      while(index < 40)
      {
          System.out.format("%10d ", Fibonacci.getElement(index));
          if (++index % 10  == 0)
              System.out.println(); 
      }
   }
}


