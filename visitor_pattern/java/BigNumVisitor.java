//package com.charlesq.java.visitorpattern;
import java.lang.Comparable;
import java.math.BigInteger;
import java.util.Random;
import org.junit.Test;
import org.junit.Assert; 
import org.junit.BeforeClass;
import org.junit.Ignore;
import org.junit.AfterClass;
import java.util.Comparator;
import java.util.ArrayList;
public class BigNumVisitor extends Visitor<BigInteger>
{
   final int pow = 6;
   Visitable<BigInteger> element;
   Comparator<BigInteger> c;
   /* keep a copy of the array */
   public BigNumVisitor()
   {
       int sz = 20; 
       Random r = new Random();
       ArrayList<BigInteger>  b = new ArrayList<BigInteger>();
       a = new BigInteger[sz];
       for (int i = 0; i < sz; ++i )
       {
           a[i] =  new BigInteger(20, r);
       }
   }
   /****** Elements visit methods start here **************/
   @Override 
   public void visit(QuickSort<BigInteger> qs)
   {
       before();
       qs.init(a);
       qs.run();
       after();
       Assert.assertTrue(isOrdered());
   }

   @Override
   public void visit(BubbleSort<BigInteger> bs)
   {
       before();
       bs.init(a);
       bs.run();
       after();
       Assert.assertTrue(isOrdered());
   }

   @Override
   public void visit(InsertSort<BigInteger> is)
   {
       before();
       is.init(a);
       is.run();
       after();
       Assert.assertTrue(isOrdered());
   }
   @Override
   public void visit(HeapSort<BigInteger> hs)
   {
       before();
       hs.init(a);
       hs.run();
       after();
       Assert.assertTrue(isOrdered());
   }
   @Override
   public void visit(MergeSort<BigInteger> ms)
   {
       before();
       ms.init(a);
       ms.run();
       after();
       Assert.assertTrue(isOrdered());
   }
   @Override
   public void visit(Algorithms<BigInteger> al)
   {
       
   }
   /****** visit methods ends here ***********************/ 
   void before()
   {
       shuffleArray();
       System.out.println(
       "++++++++++++++++++" + element.toString() + "++++++++++++++++");

       System.out.println("Prior to sorting: ");
       printArray();
   }

    public boolean isOrdered()
    {
       for (int i = 0; i + 1 < a.length; ++i)
           if (a[i].compareTo(a[i+1]) > 0)
               return false;
       return true;
    }

   void after()
   {
       System.out.println("Post sorting: ");
       printArray();
       System.out.println();
       System.out.println();
   }
   @Override
   final public void printElement(int i)
   {
       System.out.print(a[i].toString() + " ");
   } 
  @BeforeClass
   public static void beforeClass()
   {
       System.out.println(
     "**********************************************************");
       System.out.println(
     "**********    BigNumber (BigInteger)  Visitor  ***********");
       System.out.println(
     "**********************************************************");
   }
   /*********** All Test Cases Are Defined Below ****************/
   @Test
   //@Ignore
    public void testQuickSort()
    {
        QuickSort<BigInteger> qs  = new QuickSort<BigInteger>();
        element = qs;
        qs.accept(this); 
    }
    @Test
    @Ignore
    public void testBubbleSort()
    {
        BubbleSort<BigInteger> bs   = new BubbleSort<BigInteger>();
        element = bs;
        this.visit(bs);
    }
    @Test
    @Ignore
    public void testInserSort()
    {
        InsertSort<BigInteger> is = new InsertSort<BigInteger>();
        element = is;
        this.visit(is);
    }
    @Test
    @Ignore
    public void testHeapSort()
    {
        HeapSort<BigInteger> hs = new HeapSort<BigInteger>();
        element = hs;
        this.visit(hs);
    }
    @Test 
    @Ignore
    public void testMergeSort()
    {
        MergeSort<BigInteger> ms = new MergeSort<BigInteger>();
        element = ms;
        this.visit(ms);
    } 
    @Test
    //@Ignore
    public void testAlgorithms()
    {
        Algorithms<BigInteger> al = new Algorithms<BigInteger>();
        element = al;
        al.accept(this);
    }
   /*************Test Cases end here ***************************/
   @AfterClass
   public static void afterClass()
   {
       System.out.println(
       "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
       System.out.println(
       "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   }
   
    
}
