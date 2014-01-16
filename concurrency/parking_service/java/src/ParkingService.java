//package com.charles.java.parking;
import java.util.concurrent.ArrayBlockingQueue;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.logging.*;
public class ParkingService extends Entity
{
   private static ParkingService firm; 
   private static int idSeq = 0;
   private ArrayBlockingQueue<Pager> pagerDB;
   private ArrayBlockingQueue<Employee> employeeDB; 
   private int employeeNum;
   private int capacity;
   private static final String DB = "config.txt";
   private final String name = "PDX Parking Services";
   private ParkingService(BufferedReader config)
   {
       super(idSeq++);
       String line;
       try
       {
           while( (line  = config.readLine()) != null)
               parseLine(line); 
       }
       catch (IOException e)
       {
           //Logging ?
       }
   }
   public String getName()
   {
       return name;
   }
   public static ParkingService getService()
   {
      if (firm == null)
      {
          
          try
          {
              firm = new ParkingService(
                        new BufferedReader (
                        new InputStreamReader(
                        new FileInputStream(DB)
                                             )
                                             )
                                          );
          }
          catch(FileNotFoundException ex)
          {
             // Logging Event  
             
          }
      }
      return firm;
   } 
   private void setEmployeeNumber(int n)
   {
       employeeNum = n;
   } 
   private void setParkingCapacity(int n)
   {
       capacity = n;
   }
   private void parseLine(String line)
   {
       StringTokenizer stok = new StringTokenizer(line, ":");
       if (stok.hasMoreTokens())
       {
           String s = stok.nextToken();
           if (s.equalsIgnoreCase("Employees"))   
           {
               if (stok.hasMoreTokens())
               {
                   setEmployeeNumber(Integer.parseInt
                                      (stok.nextToken()));
               }
           }
          else if (s.equalsIgnoreCase("Spots"))
          {
              if (stok.hasMoreTokens())
              {
                  setParkingCapacity(Integer.parseInt( stok.nextToken()));
              }
          } 
       }
   }
}
