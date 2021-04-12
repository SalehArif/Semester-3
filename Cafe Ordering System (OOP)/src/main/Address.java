package main;

import java.io.Serializable;

public class Address  implements Serializable{

	private String home;
	private String street;
	private String city;
	
	public Address() {
		
	}
	
	public Address(String a,String b,String c) {
		home=a;
		street=b;
		city=c;
	
	}
	public Address(Address a) {
		home=a.home;
		city=a.city;
		street=a.street;
	}
	public String getHome() {
		return home;
	}
	public void setHome(String home) {
		this.home = home;
	}
	public String getStreet() {
		return street;
	}
	public void setStreet(String street) {
		this.street = street;
	}
	public String getCity() {
		return city;
	}
	public void setCity(String city) {
		this.city = city;
	}
	
	public void display() {
		System.out.println(home +" " + city + " " + street);
	}
	
	public String toString() {
		return home +", " + street + ", " + city; 
	}
	
	
}