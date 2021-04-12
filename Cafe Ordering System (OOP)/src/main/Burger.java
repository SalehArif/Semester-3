package main;

public class Burger extends Food{

	static String flavor[]={"Chicken","Zinger","Zinger Cheese","Shami Anda"};
	static int cost[]={100,150,170,80}; // setting flavors and cost for Burger
	boolean cheese;

	
	public Burger(boolean b) {
		super("Burger",flavor,cost); // Calling Food constructor to give required data members
		this.cheese=b;
	}

	@Override
	public int Calculatecost(int a){
		int price = super.Calculatecost(a); // getting price of chosen flavor
		if(this.cheese)
			price+=40; //adding Rs.40 to bill if cheese is extra
		return price;
	}
	
	public boolean isCheese() {
		return cheese;
	}


	public void setCheese(boolean cheese) {
		this.cheese = cheese;
	}


	public void display() {
		super.display();
		System.out.println(this.cheese);
	}
	

}
