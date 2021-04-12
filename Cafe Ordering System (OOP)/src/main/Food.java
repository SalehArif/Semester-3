package main;

import java.util.Scanner;


public class Food {

	private String name;
	private String[] flavor;
	private int[] cost;
	
	
	
	protected Food(String a,String[] b,int[] c) {
		name=a;
		flavor=b;
		cost=c;
	}
	
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String[] getFlavor() {
		return flavor;
	}

	public int[] getCost() {
		return cost;
	}

	public int ChooseFlavor(){
		int cho;
		System.out.println("Choose Flavor: ");
		for(int i=0;i<flavor.length;i++)
			System.out.print("\t"+(i+1)+"."+flavor[i]+"\t ");	//Printing Flavors for a certain Food 
		
		Scanner in = new Scanner(System.in);
		cho=in.nextInt();
		System.out.println();
		
			if(this instanceof Pizza)	{
				System.out.print("Do you want Extra Toppings (y/n): "); //Asking for toppings if food is Pizza
				String ch = in.next();
				Pizza p = null;
				if(ch.equalsIgnoreCase("y")) {
					p=(Pizza)this; // Downcasting and setting topping to true
					p.setToppings(true);
				}
			}
			else if(this instanceof Burger) {
				System.out.print("Do you want extra cheese with that (y/n): "); //Asking for Cheese if food is Burger
				String ch = in.next();
				Burger b = null;
				if(ch.equalsIgnoreCase("y")) {
					b = (Burger)this;
					b.setCheese(true);
			}
		}
			else if(this instanceof Fries) {
				System.out.print("Do you want extra sauce (y/n): ");
				String ch = in.next();
				Fries f = null;
				if(ch.equalsIgnoreCase("y")) {
					f = (Fries)this;
					f.setExtraSauce(true);
			}
		}
			
		
		
		if(cho<flavor.length+1 && cho>0)
			return cho;
		else
			return -1;
	}
	
	public int Calculatecost(int choice) {
		return cost[choice]; //Returning cost saved in the array related to a certain flavor index
	}

	
	public void display() {
		System.out.println(cost);
	}

}