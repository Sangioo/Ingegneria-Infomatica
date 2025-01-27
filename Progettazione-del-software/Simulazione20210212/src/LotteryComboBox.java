import javax.swing.AbstractButton;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JTextField;
import java.awt.Color;
import java.awt.Component;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

/**
 * Subclass of {@link JComboBox} that allows to select one number between 1 and 90.
 * This class also implements a mechanism for disabling user interaction,
 * to be used while the extraction is in progress.
 */
public class LotteryComboBox extends JComboBox<String> {
    private static final Color CHECK_COLOR = Color.RED;
    private final List<MouseListener> comboboxListeners = new ArrayList<>();
    private final List<MouseListener> dropdownListeners = new ArrayList<>();

    /**
     * Create a new {@code LotteryComboBox} with default selection.
     */
    public LotteryComboBox() {
        Vector<String> options = new Vector<>();
        options.add("");
        for (int i = 1 ; i <= 90 ; i++) {
            options.add(String.valueOf(i));
        }
        setModel(new DefaultComboBoxModel<>(options));
    }

    /**
     * Returns {@code true} if a number is selected, {@code false} otherwise.
     *
     * @return whether there is a number selected.
     */
    public boolean isNumberSelected() {
        return getSelectedIndex() != 0;
    }

    /**
     * Returns whether the current {@code LotteryComboBox} is checked,
     * i.e. the selected number has been extracted.
     *
     * @return whether the current number is checked.
     */
    public boolean isChecked() {
        return getForeground() == CHECK_COLOR;
    }

    /**
     * Toggle highlighting of the selected number.
     *
     * @param checked whether the current selection is highlighted or not.
     */
    public void setChecked(boolean checked) {
        setForeground(checked ? CHECK_COLOR : null);
    }

    /**
     * Returns whether the current {@code LotteryComboBox} has user interaction disabled.
     *
     * @return {@code true} if user interaction is disabled, {@code false} otherwise.
     */
    public boolean isReadOnly() {
        JTextField editor = (JTextField)getEditor().getEditorComponent();
        return !editor.isEditable();
    }

    /**
     * Toggle user interaction with this {@code LotteryComboBox}.
     * This is useful to disable user interaction while the extraction
     * is in progress.
     *
     * @param readOnly whether user interaction has to be disabled for this component.
     */
    public void setReadOnly(boolean readOnly) {
        JTextField editor = (JTextField)getEditor().getEditorComponent();
        editor.setEditable(!readOnly);

        AbstractButton dropdownButton = null;
        for (Component component : getComponents()) {
            if (component instanceof AbstractButton) {
                dropdownButton = (AbstractButton) component;
                dropdownButton.setEnabled(!readOnly);
                break;
            }
        }

        if (readOnly) {
            // Remove all mouse listeners
            for (MouseListener listener : getMouseListeners()) {
                removeMouseListener(listener);
                comboboxListeners.add(listener);
            }
            // Remove all drop-down button mouse listeners
            if (dropdownButton != null) {
                for (MouseListener listener : dropdownButton.getMouseListeners()) {
                    dropdownButton.removeMouseListener(listener);
                    dropdownListeners.add(listener);
                }
            }
        } else {
            // Re-add all combo box listeners
            for (MouseListener listener : comboboxListeners)
                addMouseListener(listener);
            comboboxListeners.clear();

            // Re-add all drop-down button listeners
            if (dropdownButton != null) {
                for (MouseListener listener : dropdownListeners)
                    dropdownButton.addMouseListener(listener);
                dropdownListeners.clear();
            }
        }
    }
}
