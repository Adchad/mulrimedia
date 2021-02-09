import java.awt.BorderLayout;

import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;
import java.net.UnknownHostException;


public class MainFrame extends JFrame {

    JTextArea title;
    JButton button1;
    JButton button2;
    JButton button3;


    Client client;

    public MainFrame(Client client) throws UnknownHostException, IOException {
        
        this.client = client;

        title = new JTextArea(6,20);

        JPanel panel = new JPanel(); 
        JScrollPane scrollPane = new JScrollPane(title);

        button1 = new JButton("Search");
        button2 = new JButton("Play");
        button3 = new JButton("Close");

        button1.addActionListener(new ButtonListener());
        button2.addActionListener(new ButtonListener());
        button3.addActionListener(new ButtonListener());


        
        add(scrollPane, BorderLayout.CENTER);
        panel.add(button1, BorderLayout.LINE_START);
        panel.add(button2, BorderLayout.CENTER);
        panel.add(button3, BorderLayout.LINE_END); 
        add(panel, BorderLayout.PAGE_END);



        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        JToolBar toolBar = new JToolBar();
        add(toolBar, BorderLayout.NORTH);

        ActionItem menuItem1 = new ActionItem("search");
        ActionItem menuItem2 = new ActionItem("play");
        ActionItem menuItem3 = new ActionItem("close");


        menu.add(menuItem1);
        toolBar.add(menuItem1);
        menu.add(menuItem2);
        toolBar.add(menuItem2);
        menu.add(menuItem3);
        toolBar.add(menuItem3);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack(); 
        setVisible(true);
    }

    private class ButtonListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {

            
            

            if(e.getSource()==button1){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Search:\n",
                    "Search",
                    JOptionPane.PLAIN_MESSAGE
                    );
                title.append("\n"+client.send("search "+s));
                
            }
            else if(e.getSource()==button2){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Play:\n",
                    "Play",
                    JOptionPane.PLAIN_MESSAGE
                    );
                title.append("\n"+client.send("play "+s));
                
            }
            else if(e.getSource()==button3){
                MainFrame.this.dispose();
            }
        }
    }

    private class ActionItem extends AbstractAction{

		private static final long serialVersionUID = 1L;

		private String name;

		@Override
		public void actionPerformed(ActionEvent arg0) {
            switch (name) {
                case "search":
                    String s = (String)JOptionPane.showInputDialog(
                        MainFrame.this,
                        "Search:\n",
                        "Search",
                        JOptionPane.PLAIN_MESSAGE
                        );
                    title.append("\n"+client.send("search "+s));
                    break;
            
                case "play":
                    String s1 = (String)JOptionPane.showInputDialog(
                        MainFrame.this,
                        "Play:\n",
                        "Play",
                        JOptionPane.PLAIN_MESSAGE
                        );
                    title.append("\n"+client.send("play "+s1));

                    break;
                
                case "close":
                    MainFrame.this.dispose();
                    break;
            }
		}

        public ActionItem(String name){
            super(name);
            this.name = name;
        }
    }

    private static final long serialVersionUID = 1L;
}
