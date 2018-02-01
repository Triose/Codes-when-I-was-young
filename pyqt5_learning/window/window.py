import sys
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QIcon

class App(QWidget):

    def __init__(self):
        # initialize some attributes of the window
        super().__init__()
        self.title = "Hello World"
        self.left = 10
        self.top = 10
        self.width = 640
        self.height = 480
        self.initUI()

    def initUI(self):
        # initialize and display the window
        self.setWindowTitle(self.title)         # set the title of the window
        self.setGeometry(self.left, self.top, self.width, self.height)  # set location of the window
        self.show()     # display the window

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())



