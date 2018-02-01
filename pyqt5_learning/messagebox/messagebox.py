# We use the method QMessageBox.question() to display the messagebox

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QWidget):
    
    def __init__(self):
        super().__init__()
        self.title = "PyQt5 messagebox"
        self.left, self.top = 10, 10
        self.width, self.height = 320, 200
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        buttonReply = QMessageBox.question(self, 
                "PyQt5 message", 
                "Do you like PYQT?", 
                QMessageBox.Yes | QMessageBox.No, 
                QMessageBox.Yes)           
        # "PyQt5 message" is the title of messagebox, "Do you.." is the content of the messagebox, QMessageBox.yes|.. is the option of messagebox, QMessageBox.No is the default option of messagebox 
        if buttonReply == QMessageBox.Yes:
            print("Yes clicked.")
        else:
            print("No clicked.")

        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())




