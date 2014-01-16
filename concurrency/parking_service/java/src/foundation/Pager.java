//package com.charlesq.java.parking;
import java.util.concurrent.ArrayBlockingQueue;
import java.lang.Thread;
import java.util.logging.*;
import java.lang.InterruptedException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Callable;

public class Pager
{
   private  Entity carrier;
   private final ExecutorService pagingCenter;
   public Pager( ExecutorService pc)
   {
       this.pagingCenter = pc;
   }
   public void postMessage(Message m)
   {
       pagingCenter.submit(m);
   }
   public synchronized void setCarrier(Entity en) 
   {
       this.carrier = en;
   }
}
