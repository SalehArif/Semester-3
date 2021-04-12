package main;

import java.io.Serializable;
import java.util.ArrayList;

public class Order implements Serializable{

	ArrayList<String> item = new ArrayList<String>(0);
	ArrayList<Integer> quantity =new ArrayList<Integer>(0);
	ArrayList<Integer> price =new ArrayList<Integer>(0);
	
	private double totalBill;
	private Customer c;
	private boolean delivery;
	private boolean discount;

	public Order() {
		
	}
	
	public Order(boolean b) {
		this.totalBill=0;
		this.delivery=b;
	}
	
	public Customer getC() {
		return new Customer(c);
	}

	public void setC(Customer a) {
		this.c = new Customer(a);
	}

	public boolean isDelivery() {
		return delivery;
	}

	public void setDelivery(boolean delivery) {
		this.delivery = delivery;
	}

	public boolean isDiscount() {
		return discount;
	}

	public void setDiscount(boolean discount) {
		this.discount = discount;
	}

	public void setTotalBill(double totalBill) {
		this.totalBill = totalBill;
	}

	
	public double Bill() { //GetBill()
		return this.totalBill;
	}
	
	public double applyDiscount() {
		double i= this.totalBill - this.totalBill*0.1; //Subtracting 10% and returning it in a separate variable 
		return i;										// to not change bill when saving
	}
	
	public void addtocart(Food a, int ind) {

		String yes= a.getFlavor()[ind]+" "+a.getName(); //Getting name of Flavor from Array + the Name of food
		if(item.contains(yes)) { //Checking ArrayList if it contains that food
			ind = item.indexOf(yes);
			quantity.add(ind, quantity.get(ind)+1); // If it does then add to Quantity and price
			price.add(price.get(ind)+a.getCost()[ind]);
		}
		else { 									// Otherwise add the food and its price with 1 quantity
			item.add(yes); 
			quantity.add(1);
			price.add(a.getCost()[ind]);
		}
		//Since these food have special members, we need extra conditions
		if(a instanceof Burger)		 // if food is burger then check Boolean for Cheese 
			if(((Burger) a).isCheese()) {
				if(item.contains("Cheese")) { //if it already exists in ArrayList then add to quantity and price
					quantity.add(ind+1, quantity.get(ind+1)+1);
					price.add(price.get(ind+1)+40);
				}else { 						// Otherwise add the food and its price with 1 quantity
				item.add("Cheese");
				quantity.add(1);
				price.add(40);
				}
				}
		if(a instanceof Fries)
			if(((Fries) a).isExtraSauce()) {
				if(item.contains("Extra Sauce")) {
					quantity.add(ind+1, quantity.get(ind+1)+1);
					price.add(price.get(ind+1)+20);
				}else {
				item.add("Extra Sauce");
				quantity.add(1);
				price.add(20);
				}
				}
		
	}
	public void addtocart(Food a, int ind,int in) { //Since Pizza food type can have different indexes for chosen flavor and size
		String yes= a.getFlavor()[ind]+" "+a.getName(); // we need another method to accommodate it correctly
		if(item.contains(yes)) {
			ind = item.indexOf(yes);
			quantity.add(ind, quantity.get(ind)+1);	// similar to the code above but using the correct indexes 
			price.add(price.get(in)+a.getCost()[in]); //passed as parameters to the method
		}
		else {
			item.add(yes);
			quantity.add(1);
			price.add(a.getCost()[in]);
			}
		if(a instanceof Pizza)
			if(((Pizza) a).isToppings()) {
				if(item.contains("Topping")) {
					quantity.add(ind+1, quantity.get(ind+1)+1);
					price.add(price.get(ind+1)+50);
				}else {
					item.add("Topping");
					quantity.add(1);
					price.add(50);
					}
				}
	}

	public void receipt() {
		System.out.println("\t\t\tReceipt\n"); 
		System.out.println("Customer Name: "+c.getName()); //Using customer object to get name
		System.out.print("Home Delivery: ");
		if(this.delivery) { //If the order is to be home delivered, print address
			System.out.println("Yes");
			System.out.println("Delivered to: "+c.getHome().toString()+"\n"); //Getting address from Customer Object's "home" data member
		}else
			System.out.println("No\n");
		
		System.out.println("S#\tItem\t\t   Quantity\t\tPrice");
		
		for(int i=0;i<item.size();i++)
			System.out.println(i+1+"\t"+item.get(i)+"\t\t"+quantity.get(i) +"\t\t"+price.get(i)); //Printing previously saved ArrayLists
		System.out.println("\nTotal Bill: "+this.Bill()); //printing total bill
		if(this.discount)
			System.out.println("Discounted Bill: "+this.applyDiscount()); // Applying discount if customer has Membership
	}
	
	public void display() {
		c.display();
		System.out.println(this.totalBill+" "+this.delivery+" "+this.discount);
	}
}
