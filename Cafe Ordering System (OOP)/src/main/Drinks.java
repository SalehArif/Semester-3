package main;

public class Drinks extends Food{

	static String flavors[] = {"Soda","Juice","Tea","Coffee","Water"};
	static int cost[]={50,30,30,80,20}; // setting flavors and cost for Drinks

	
	public Drinks() {
		super("Drink",flavors,cost); // Calling Food constructor to give required data members
		
	}

	
}
