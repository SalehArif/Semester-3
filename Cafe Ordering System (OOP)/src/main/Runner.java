package main;

import java.util.ArrayList;
import java.util.Scanner;


public class Runner {
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) {
		int choice;	 // Variable needed to make choices or Data for objects
		int ind;
		String name;
		String yes;
		boolean done=false;
		int i=-1;
		
		Customer ca = null;
		Address ad = null;
		Order o=new Order(false);
		
		do{
			System.out.println("\n\t\t\tMain Menu");
		System.out.print("1.New Order\t2.Members\t3.Search orders by name\t\t4.Exit ");
		ind = in.nextInt();
		System.out.println();
		switch(ind) {
		case 4:
			System.out.println("\nExiting....");
			break;
		case 2: // Display Members
			ArrayList<Customer> memb = FileOperations.readAllData();
			for(int j=0;j<memb.size();j++)
				System.out.println(j+1+"."+memb.get(j).getName());
			break;
		case 3: // Display Orders by specific Member Customer
			System.out.print("Enter your name: ");
			name= in.next();
			System.out.println();
			i= FileOperations.search(name);
			if(i!=-1) {
				ArrayList<Order> ord = FileOperations.readAllData1();
				String abc;
				for(int j=0;j<ord.size();j++) {
					abc = ord.get(j).getC().getName();
					if((abc).equals(name)){
						ord.get(j).receipt();
						System.out.println();
			}}
			}
			else
				System.out.println("\nNot a Member.");
			break;
		case 1:
			do{ //Make a new Order by a member or new Customer and add Details required to order for new customer
				System.out.println("\t\t\tNew Order");	
				System.out.print("\t1.Existing Member\t2.New Customer ");
				choice = in.nextInt();
				System.out.println();
				if(choice==1) {
					System.out.print("Enter your name: "); //Searching for typed name in Members
					name= in.next();
					System.out.println();
					i= FileOperations.search(name);
					if(i!=-1) {
						ArrayList<Customer> mem = FileOperations.readAllData();
						System.out.println("Welcome Back "+mem.get(i).getName()+"\n");
						o.setDiscount(true);
						ca=mem.get(i);
						o.setC(ca);
					}else
						System.out.println("\nNot a Member.");
				}
				if(choice==2 || (choice==1 && i==-1)){ //If new customer enter details also add address if want to be Member
					System.out.print("Enter your name and Phone number: ");
					name= in.next();
					String num= in.next();
					System.out.println();
					System.out.print("You want to be a Member and get 10% Discount? y/n ");
					yes=in.next();
					System.out.println();
					if(yes.equalsIgnoreCase("y")) {
					
					String[] add= new String[3];
					System.out.print("Please Give Address. Enter home address:\n"
							+ "(Omit any spaces as Split and Nextline method gave unresolvable exceptions) ");
					add[0]=in.next();
					System.out.print("Enter Street: ");
					add[1]=in.next();
					System.out.print("Enter City: ");
					add[2]=in.next();
					
					ad = new Address(add[0],add[1],add[2]);
					
					ca = new Customer(name,ad,num);
					ca.setMember(true);
					o.setDiscount(true);
					o.setC(ca);
					FileOperations.writeToFile(ca);
					}else {
						ca = new Customer(name,num);
						ca.setMember(false);
						o.setDiscount(false);
						o.setC(ca);
					}
				}
				}while(choice!=1 && choice!=2);
				
				System.out.print("Do you need the Food to be Delivered? y/n "); //Home delivery?
				yes=in.next();
				System.out.println();
				if(yes.equalsIgnoreCase("y")) {
					o.setDelivery(true);
					
					if(!ca.isMember()) { // Add address if not Member as member's address is already known
					String[] add= new String[3];
					System.out.print("Please Give address. Enter your Home address:\n"
					+"(Omit any spaces as Split and Nextline methods gave unresolvable exceptions) ");
					add[0]=in.next();
					System.out.print("Enter Street: ");
					add[1]=in.next();
					System.out.print("Enter City: ");
					add[2]=in.next();
					
					ad = new Address(add[0],add[1],add[2]);
					ca.setHome(ad);
					o.setC(ca);
					}
				}else {
					o.setDelivery(false);
				}
				done=false;
				while(!done) {
					menu(o); // Display menu
					System.out.print("Do you want to Buy anything else? (y/n) ");
					yes=in.next();
					System.out.println();
					if(!yes.equalsIgnoreCase("y"))
						done=true;
				}
				
				
				o.receipt(); // Display receipt
				
				FileOperations.writeToFile(o); //Write order to file
				o.item.clear();o.quantity.clear();o.price.clear(); o.setTotalBill(0);
			break;
		default:
			System.out.println("Invalid Option. ");
		}
		}while(ind!=4);
		
	}
	
	public static void menu(Order o) {
		System.out.print("\t\tMenu\n1.Burger\n2.Pizza\n3.Fries\n4.Chicken\n5.Drinks ");
		int choice = in.nextInt();
		System.out.println();
		int ind;
		int i;
		switch(choice) {
		
		case 1:
			Burger a = new Burger(false); //making food object
			ind=a.ChooseFlavor(); //choosing flavor of food using method from food class
			o.setTotalBill(o.Bill()+a.Calculatecost(ind-1)); //increasing total bill by amount of chosen food
			o.addtocart(a,ind-1); //adding to ArrayList to be shown later
			break;
		case 2:
			Pizza b = new Pizza(false);
			ind=b.ChooseFlavor();
			i=b.chooseSize();
			o.setTotalBill(o.Bill()+b.Calculatecost(i-1)); // increasing price according to the size 
			o.addtocart(b,ind-1,i-1); //adding to cart using overloaded method
			break;
		case 3:
			Fries c = new Fries(false);
			ind=c.ChooseFlavor();
			o.setTotalBill(o.Bill()+c.Calculatecost(ind-1));
			o.addtocart(c,ind-1);
			break;
		case 4:
			Chicken d = new Chicken();
			ind=d.ChooseFlavor();
			o.setTotalBill(o.Bill()+d.Calculatecost(ind-1));
			o.addtocart(d,ind-1);
			break;
		case 5:
			Drinks e = new Drinks();
			ind=e.ChooseFlavor();
			o.setTotalBill(o.Bill()+e.Calculatecost(ind-1));
			o.addtocart(e,ind-1);
			break;
		default:
			System.out.println("Invalid Option");
		}
	}
	
}
