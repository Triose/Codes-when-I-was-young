# Graphical applications are event-driven---a users action like clicks a button or selecting an item in a list is called an event.
# If an event takes place, each PyQt5 widget can emit a signal. A signal does not execute any action, that(action) is done by a slot

# In last capter, I viewed this line as a connection between an event and a function executing according code
# button.clicked.connect(self.slot_method)
# In this capter, the tutorial gives us a more specific explaination:
# That line connects the button click(signal) and the action(slot)
# the slot_method will be called if the signal emits

# Appling to all widgets, the following line is the principle of connection slots methods or function to a widget
# widget.signal.connect(slot_method)
# or, in the next line, we can also explicitly define the signal:
# QtCore.QObject.connect(widget, QtCore, SIGNAL('signalname'), slot_function)   # function, not method

# PyQt supports many type of signals-not just clicks

from PyQt5.QtWidgets import (QApplication, QComboBox, QDialog, QDialogButtonBox, QFormLayout, QGridLayout, 
                             QLabel, QLineEdit, QMenu, QMenuBar, QPushButton, QSpinBox, QTextEdit,
                             QVBoxLayout)
import sys

class Dialog(QDialog):

    def slot_method(self):
        print("Slot method called.")

    def __init__(self):
        super(Dialog, self).__init__()

        button = QPushButton("Click")
        button.clicked.connect(self.slot_method)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(button)

        self.setLayout(mainLayout)
        self.setWindowTitle("Button Example")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    dialog = Dialog()
    sys.exit(dialog.exec_())







