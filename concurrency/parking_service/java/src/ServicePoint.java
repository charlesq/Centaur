//package com.charles.java.parking;
public abstract class ServicePoint extends Entity
{
    private Pager pager;
    public ServicePoint (int id)
    {
        super(id);
        pager = ParkingService.getService().getPager();
    } 
}
