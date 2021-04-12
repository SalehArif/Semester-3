package main;

public class Fries extends Food{

	static String flavor[]={"Plain","Curled","Tornado","Chilli"};
	static int cost[]={60,100,100,120}; // setting flavors and cost for Fries
	boolean extraSauce;

	
	public Fries(boolean a) {
		super("Fries",flavor,cost); // Calling Food constructor to give required data members
		this.extraSauce=a;
	}

	@Override
	public int Calculatecost(int choice){
		int price=super.Calculatecost(choice); // getting price of chosen flavor
		if(this.extraSauce)
			price+=20; //adding Rs.20 to bill if sauce is extra
		return price;
	}

	public boolean isExtraSauce() {
		return extraSauce;
	}

	public void setExtraSauce(boolean extraSauce) {
		this.extraSauce = extraSauce;
	}
	

	public void display() {
		super.display();
		System.out.println(this.extraSauce);
	}
}
