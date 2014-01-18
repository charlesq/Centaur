//package com.charles.java.parking;
import java.util.concurrent.ArrayBlockingQueue;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.logging.*;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class ParkingService extends Entity
{
   private static ParkingService firm; 
   private static int idSeq = 0;
   private ArrayBlockingQueue<Pager> pagerNotInUseDB;
   private ArrayBlockingQueue<Pager> pagerInUseDB;
   private ArrayBlockingQueue<Employee> employeeDB; 
   private int employeeNum;
   private int capacity;
   private static final String DB = "config.txt";
   private final String name = "PDX Parking Services LLC";
   private ConcurrentMap<Vehicle, Spot> v2spot; 
   private final ExecutorService pagingCenter;
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
       establishEmployeeDB();
       establishPagerDB();
       v2spot = new ConcurrentHashMap<Vehicle, Spot>();
       pagingCenter = Executors.newFixedThreadPool(employeeNum * 2);
       
   }
   public final ExecutorService getPagingCenter()
   {
       return pagingCenter;
   }
   public String name()
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

   synchronized boolean addNewEmployee()
   {
       if (employeeDB.remainingCapacity() == 0)
       {
           /* log event ?*/
           return false; 
       }
       employeeDB.offer(new Employee(idSeq++));
       return true;
   }
   synchronized boolean addNewPager()
   {
       if (pagerNotInUseDB.remainingCapacity() == 0)
       {
           /* log event ?*/
           return false;
       }
       pagerNotInUseDB.offer(new Pager(idSeq++));
       return true;
   }
   private void establishEmployeeDB()
   {
       int i = 0;
       /* set capacity to twice of current employee number for new hiring */
       employeeDB = new ArrayBlockingQueue<Employee>(employeeNum * 2);
       while(i++ < employeeNum)
           addNewEmployee();
   }
   private void establishPagerDB()
   {
      int i = 0; // provisioned to one pager for each employee , one for each spot*/
      pagerNotInUseDB = new ArrayBlockingQueue<Pager>(employeeNum * 2 + capacity);
      pagerInUseDB = new ArrayBlockingQueue<Pager>(employeeNum * 2 + capacity);
      while(i++ < employeeNum + capacity)
         addNewPager();
   }
   private void establishSpotsDB()
   {
       int i = 0;
   }
   synchronized Pager getPager()
   {
       Pager p =  pagerNotInUseDB.poll();     
       pagerInUseDB.offer(p);
       return p;
      
   }
   synchronized void returnPager(Pager p)
   {
      pagerInUseDB.remove(p); 
      pagerNotInUseDB.offer(p);
   }
   
}
