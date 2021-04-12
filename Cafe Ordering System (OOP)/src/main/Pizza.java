package main;

import java.util.Scanner;

public class Pizza extends Food {

	private static String flavor[]={"Fajita","Pepperoni","Italian","BBQ"};  // setting flavors cost and size for Pizza
	private static String[] size = {"Small","Medium","Large","Family"};
	private static int cost[]={400,600,900,1200};
	private boolean toppings;

	
	public Pizza(boolean b) {
		super("Pizza",flavor,cost); // Calling Food constructor to give required data members
		this.toppings=b;
	}

	@Override
	public int Calculatecost(int a){
		int price = super.Calculatecost(a); // getting price of chosen size
		if(this.toppings)
			price+=50; //adding Rs.50 to bill if toppings are extra
		return price;
	}
	
	public boolean isToppings() {
		return toppings;
	}

	public void setToppings(boolean toppings) {
		this.toppings = toppings;
	}
	
	
	public int chooseSize() {
		int cho;
		Scanner in = new Scanner(System.in);
		System.out.println("\nWhich Size do you Want: ");
		for(int i=0;i<size.length;i++)
			System.out.print("\t\t"+(i+1)+"."+size[i]+"\t "); //Printing sizes and choosing to calculate price correctly
		cho=in.nextInt();
		System.out.println();
		if(cho>0 && cho<size.length+1)
			return cho;
		else
			return -1;
	}

	public void display() {
		super.display();
		System.out.println(this.toppings);
	}

}