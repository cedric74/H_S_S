package com.cedric.toncanier.compteurvelo;

public class Data {
	
	private long lId;
	private float fSpeed;
	private float fDistance;
	private String sTime;
	private String sDate;
	
	
	public Data(long lId, float fSpeed, float fDistance, String sTime,
			String sDate) {
		super();
		this.lId = lId;
		this.fSpeed = fSpeed;
		this.fDistance = fDistance;
		this.sTime = sTime;
		this.sDate = sDate;
	}
	public long getlId() {
		return lId;
	}
	public void setlId(long lId) {
		this.lId = lId;
	}
	public float getfSpeed() {
		return fSpeed;
	}
	public void setfSpeed(float fSpeed) {
		this.fSpeed = fSpeed;
	}
	public float getfDistance() {
		return fDistance;
	}
	public void setfDistance(float fDistance) {
		this.fDistance = fDistance;
	}
	public String getsTime() {
		return sTime;
	}
	public void setsTime(String sTime) {
		this.sTime = sTime;
	}
	public String getsDate() {
		return sDate;
	}
	public void setsDate(String sDate) {
		this.sDate = sDate;
	}

	
}
