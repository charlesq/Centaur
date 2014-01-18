//package com.charles.java.parking;
public class Spot extends Entity
{
     boolean vacant = false;
     private Vehicle v = null;
     Sensors sensors;
     class Sensors
     {
        String readLicense(final Vehicle v)
        {
            if (v != null)
                return v.licenseNum;
            return null;
        } 
        boolean isOccupied(final Vehicle v)
        {
            return v != null;
        } 
     }
     public Spot(int id)
     {
         super(id);
         sensors = new Sensors(); 
     }
     public synchronized boolean park(Vehicle v)
     {
         if (this.v != null)
            return false;
         this.v = v;
         return true;
     }
} 
