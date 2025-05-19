import javax.swing.*;
import java.awt.*;
 public class SwingEX3 {
    public static void main(String args[]) {

        JFrame jf = new JFrame("Swing Form");
        

        Container c = jf.getContentPane();
        c.setLayout(new GridLayout(4, 2, 10, 10)); 

        JLabel l1 = new JLabel("Full Name:");
        JTextField t1 = new JTextField(10);

        JLabel l2 = new JLabel("College Name:");
        JTextField t2 = new JTextField(10);

        JLabel l3 = new JLabel("Department Name:");
        JTextField t3 = new JTextField(10);

        JButton b1 = new JButton("Submit");
        JButton b2 = new JButton("Clear");

        c.add(l1);
        c.add(t1);
        c.add(l2);
        c.add(t2);
        c.add(l3);
        c.add(t3);
        c.add(b1);
        c.add(b2);

        jf.setSize(400, 200);
        jf.setVisible(true);
    }
}
