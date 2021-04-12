package main;

import java.io.Serializable;

public class Customer implements Serializable{

	private String name;
	private Address home;
	private String phone;
	private boolean member;
	
	public Customer() {

	} 

	public Customer(String a,String d) {
		this.name=a;this.phone=d;member=false;
	}
	
	public Customer(String a,Address b,String d) {
		this.name=a; this.home=new Address(b); this.phone=d;member=false;
	}
	
	public Customer(Customer a) {
		if(a.home!=null)
			this.home=new Address(a.home);
		this.name=a.name; this.phone=a.phone; member=a.member;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Address getHome() {
		return new Address(home);
	}
	public void setHome(Address hom) {
		this.home = new Address(hom);
	}
	public String getPhone() {
		return phone;
	}
	public void setPhone(String phone) {
		this.phone = phone;
	}
	

	public boolean isMember() {
		return member;
	}

	public void setMember(boolean member) {
		this.member = member;
	}

	
	public void display() {
		System.out.println("Name: "+name+"\nPhone Number: "+phone+"\nMembership: "+member);
		home.display();
	}
		
	
}
