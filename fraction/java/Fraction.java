import java.lang.Object;
import java.lang.String;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.lang.StringBuilder;
import java.util.ArrayList;
public 
class Fraction extends Object
{
   private final int numerator;
   private final int denominator;
   private String frac;
   public Fraction (int numerator, int denominator)
   {
       this.numerator = numerator;
       this.denominator = denominator;
   }
   private void fractional()
   {
       StringBuilder sb = new StringBuilder();
       if (denominator == 0)
       {
           frac = "INFINITY";
           return;
       }
       if (numerator == 0)
       {
           frac = "0";
           return;
       }
       int num = numerator, den = denominator;
       ArrayList<Integer> remainders = new ArrayList<Integer>(),
                          quotients = new ArrayList<Integer>();
       if (num < 0 | den< 0)
       {
           if (!(num < 0 && den < 0))
               sb.append('-');
           num = num < 0 ?-num: num;
           den = den < 0? -den: den;
       }
       if (num > den) 
       {
           sb.append(num/den);
           num = num % den;
           if (num == 0)
           {
 
               frac = sb.toString();
               return;
           }
       }
       else
          sb.append(0);
       sb.append('.');
       int repeatPoint = -1;
       while(num != 0)
       {
           repeatPoint =  remainders.indexOf(num%den);
           if (repeatPoint != -1)
              break; 
           remainders.add(num);
           num *= 10;  
           while(num < den)
           {
               quotients.add(0);
               num *= 10;
           }
           quotients.add(num / den);
           num = num %den;
       }
       int index = 0;
       while (index + 1 <= quotients.size())
       {
             
           if (repeatPoint != -1 && repeatPoint == index)
               sb.append('(');
           sb.append(quotients.get(index++));
       }
       if (repeatPoint != -1)
          sb.append(')'); 
       frac = sb.toString();
   }
   @Override
   public String toString()
   {
       if (frac == null)
           fractional();
       return frac;
   }
   public static void main(String []args) throws IOException
   {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
      int denominator, numerator;
      System.out.println("Input the numerator:");    
      while(true)
      {
         numerator = Integer.parseInt(br.readLine()); 
         System.out.println("input the denominator:"); 
         denominator = Integer.parseInt(br.readLine());   
         Fraction f = new Fraction(numerator, denominator);
         System.out.println("quotient is " + f.toString());
         System.out.print("Exit(Y/N)"); 
         String str = br.readLine();
         System.out.println(str + str.length());
         if (str.equalsIgnoreCase("Y"))
             break;
         System.out.println("Input the numerator:");
      }
   }
}
