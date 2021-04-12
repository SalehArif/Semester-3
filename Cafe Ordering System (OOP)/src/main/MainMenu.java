package main;

import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MainMenu {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainMenu window = new MainMenu();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainMenu() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setVisible(true);
		
		JPanel panel = new JPanel();
		panel.setBounds(43, 28, 342, 207);
		frame.getContentPane().add(panel);
		panel.setLayout(null);
		
		JButton btnNewButton = new JButton("New Order");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new NewOrder();
				frame.dispose();
			}
		});
		
		btnNewButton.setBounds(41, 73, 102, 23);
		panel.add(btnNewButton);
		
		JLabel lblNewLabel = new JLabel("Main Menu");
		lblNewLabel.setBounds(118, 11, 83, 19);
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 15));
		panel.add(lblNewLabel);
		
		JButton btnMembers = new JButton("Members");
		btnMembers.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new Members();
				frame.dispose();
			}
		});
		btnMembers.setBounds(180, 73, 89, 23);
		panel.add(btnMembers);
		
		JButton btnOrders = new JButton("Order History");
		btnOrders.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new HIstory();
				frame.dispose();
			}
		});
		btnOrders.setBounds(100, 107, 121, 23);
		panel.add(btnOrders);
		
		JButton btnExit = new JButton("Exit");
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				frame.dispose();
			}
		});
		btnExit.setBounds(121, 173, 89, 23);
		panel.add(btnExit);
	}

}
