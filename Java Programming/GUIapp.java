import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GUIapp {
    public static void main(String[] args) {

        JFrame frame = new JFrame("GUI app");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new FlowLayout());

        JTextField textField = new JTextField(20);
        JButton button = new JButton("GUI text");
        JLabel label = new JLabel("Enter the text and click the button.");

        String[] options = {"Option 1", "Option 2", "Option 3"};
        JComboBox<String> comboBox = new JComboBox<>(options);

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String input = textField.getText();
                String selectedOption = (String) comboBox.getSelectedItem();
                label.setText("You entered: " + input + " | Selected: " + selectedOption);
            }
        });

        frame.add(label);
        frame.add(textField);
        frame.add(comboBox);
        frame.add(button);
        frame.setVisible(true);
    }
}

