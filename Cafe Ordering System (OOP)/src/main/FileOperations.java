package main;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;


public class FileOperations {
    
     public static void writeToFile (Object s)
     {
         ObjectOutputStream outputStream = null;

		try {
			Customer d = null;        
			Order e = null;
			String file = null;
			ArrayList<Customer> CustomerList = null;
			ArrayList<Order> OrderList = null;
			if(s instanceof Customer) {  //Using instacneof to check which file to write to then downcasting and proceeding
				d = (Customer) s;
				CustomerList = readAllData();
				file="List.ser";
				CustomerList.add(d);
			}else if(s instanceof Order) {
				e= (Order) s;
				OrderList = readAllData1();
				file="Orders.ser";
				OrderList.add(e);
			}
				outputStream = new ObjectOutputStream(new FileOutputStream(file));
			
			if(e==null)
				for(int i = 0 ; i < CustomerList.size() ; i++) {
					outputStream.writeObject(CustomerList.get(i));
				}
			else
				for(int i = 0 ; i < OrderList.size() ; i++) {
					outputStream.writeObject(OrderList.get(i));
				}
		} catch(IOException e) {
			System.out.println("IO Exception while opening file");
		} finally {
			try {
				if(outputStream != null) {
					outputStream.close();								
				}

			} catch (IOException e) {
				System.out.println("IO Exception while closing file");
			}
		}		
	}
    
    public static ArrayList <Customer>  readAllData (){  //reading from Customer File
		ArrayList<Customer> CustomerList = new ArrayList<Customer>(0);
		ObjectInputStream inputStream = null;
		try
		{
		inputStream = new ObjectInputStream(new FileInputStream("List.ser"));
			boolean EOF = false;
			while(!EOF) {
				try {
					Customer myObj = (Customer) inputStream.readObject();
					CustomerList.add(myObj);
				} catch (ClassNotFoundException e) {
					System.out.println("Class not found");
				} catch (EOFException end) {
					EOF = true;
				}
                        }
                }
		 catch(FileNotFoundException e) {
			System.out.println("Cannot find file");
		} catch (IOException e) {
			System.out.println("IO Exception while opening stream");
		} finally {
			try {
				if(inputStream != null)
					inputStream.close( );
			} catch (IOException e) {
				System.out.println("IO Exception while closing file");
			}
		}
                

		return CustomerList;
	}
    
    public static ArrayList <Order>  readAllData1(){ //reading from Order File
		ArrayList<Order> OrderList = new ArrayList<Order>(0);
		ObjectInputStream inputStream = null;
		try
		{
		inputStream = new ObjectInputStream(new FileInputStream("Orders.ser"));
			boolean EOF = false;
			while(!EOF) {
				try {
					Order myObj = (Order) inputStream.readObject();
					OrderList.add(myObj);
				} catch (ClassNotFoundException e) {
					System.out.println("Class not found");
				} catch (EOFException end) {
					EOF = true;
				}
                        }
                }
		 catch(FileNotFoundException e) {
			System.out.println("Cannot find file");
		} catch (IOException e) {
			System.out.println("IO Exception while opening stream");
		} finally {
			try {
				if(inputStream != null)
					inputStream.close( );
			} catch (IOException e) {
				System.out.println("IO Exception while closing file");
			}
		}
                
		return OrderList;
	}
    
    public static int search (String name)
    {
        ArrayList<Customer> list = readAllData();
        
        int in=-1;
        for( int i=0; i< list.size();i++){
            if (list.get(i).getName().equalsIgnoreCase(name)){
                in=i;
                break;
            }
        }
        return in; // -1 if not found, otherwise index of the Name 
    }
            
}
