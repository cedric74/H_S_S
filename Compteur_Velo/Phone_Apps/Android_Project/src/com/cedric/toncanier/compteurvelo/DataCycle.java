package com.cedric.toncanier.compteurvelo;

public class DataCycle {
	   private double dTotalDistance;
	    private double dCurrentSpeed;
	    private double dAverageSpeed;
	    private double dTotalTime;

	    protected double dStep;

	    public DataCycle() {
	        this.initDataCycle();
	    }

	    public void initDataCycle() {
	        dTotalDistance = 0;
	        dCurrentSpeed = 0;
	        dAverageSpeed = 0;
	        dTotalTime = 0;
	        dStep = 0;
	    }

	    public void addDataCycle(int iCountRound) {
	        if (iCountRound == 0) {
	            dCurrentSpeed = 0;
	        } else {
	            // Convert Count Round to Distance
	            double dDistance = (iCountRound / 1000);
	            dDistance = dDistance + ((iCountRound - dDistance * 1000) * 0.001);

	            // Total Distance
	            dTotalDistance += (dDistance / 1000);

	            // Current Speed
	            dCurrentSpeed = dDistance / 5; //     TICK_DATA,   m/s
	            dCurrentSpeed = (dCurrentSpeed * 3600) / 1000;

	            // Total Time
	            dTotalTime += 5; // TICK_DATA

	            // Average Speed
	            //  V = D/t
	            dAverageSpeed = (dTotalDistance / dTotalTime) * 3600;

	            // DEbug
	            dStep = iCountRound;
	        }
	    }

	    public double getdTotalDistance() {
	        return dTotalDistance;
	    }

	    public void setdTotalDistance(double dTotalDistance) {
	        this.dTotalDistance = dTotalDistance;
	    }

	    public double getdCurrentSpeed() {
	        return dCurrentSpeed;
	    }

	    public void setdCurrentSpeed(double dCurrentSpeed) {
	        this.dCurrentSpeed = dCurrentSpeed;
	    }

	    public double getdAverageSpeed() {
	        return dAverageSpeed;
	    }

	    public void setdAverageSpeed(double dAverageSpeed) {
	        this.dAverageSpeed = dAverageSpeed;
	    }

	    public double getdTotalTime() {
	        return dTotalTime;
	    }

	    public void setdTotalTime(double dTotalTime) {
	        this.dTotalTime = dTotalTime;
	    }

	    public double getdStep() {
	        return dStep;
	    }

	    public void setdStep(double dStep) {
	        this.dStep = dStep;
	    }
}
