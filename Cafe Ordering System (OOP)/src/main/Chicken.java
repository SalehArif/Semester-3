package main;

public class Chicken extends Food{

	
	static String flavor[]={"Drumsticks","Wings","HotShots","Fried Piece"};
	static int cost[]={180,150,160,150}; // setting flavors and cost for Chicken

	
	public Chicken() {
		super("Chicken",flavor,cost); // Calling Food constructor to give required data members
	}

	
}
