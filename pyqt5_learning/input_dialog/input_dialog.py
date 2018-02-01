import sys
from PyQt5.QtWidgets import QApplication, QWidget, QInputDialog, QLineEdit
from PyQt5.QtGui import QIcon

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = "PyQt5 input dialogs"
        self.geo = (10, 10, 640, 480)

        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(*self.geo)

        self.getInteger()
        self.getDouble()
        self.getText()
        self.getChoice()

        self.show()

    def getInteger(self):
        # Parameters in order: self, window title, label(before input box), default value, minimum, maximum and step size
        i, okPressed = QInputDialog.getInt(self, "Get integer", "Percentage:", 28, 0, 100, 1)
        if okPressed:
            print(i)

    def getDouble(self):
        # The last parameter(10) is the number of decimals behind the comma.
        d, okPressed = QInputDialog.getDouble(self, "Get double", "Value:", 10.50, 0, 100, 10)
        if okPressed:
            print(d)

    def getChoice(self):
        items = ("Red", "Blue", "Green")
        # 
        item, okPressed = QInputDialog.getItem(self, "Get item", "Color:", items, 0, False)
        if okPressed and item:
            print(item)
        
    def getText(self):
        #
        text, okPressed = QInputDialog.getText(self, "Get text", "Your name:", QLineEdit.Normal, "")
        if okPressed and text != "":
            print(text)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())









