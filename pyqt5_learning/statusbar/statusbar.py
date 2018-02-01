# To add a status bar, add the following line:
# self.statusBar().showMessage("Message content")


import sys
from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from PyQt5.QtGui import QIcon

class App(QMainWindow):

    def __init__(self):
        # As same as the aforementioned code
        super().__init__()
        self.title = "PyQt5 status bar example"
        self.left = 10
        self.top = 10
        self.width = 640
        self.height = 480
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.statusBar().showMessage("Example message in statusbar.")       # The key difference lies on here
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())



