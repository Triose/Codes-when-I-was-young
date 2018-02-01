# PyQt5 supports buttons using the QPushButton class
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 button test'
        self.left = 10
        self.top = 10
        self.width = 320
        self.height = 200
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        button = QPushButton('Example button', self)
        button.setToolTip('This is an example button')
        button.move(100, 70)            # position
        button.clicked.connect(self.on_click)       # connecting the button and the fucntion needing to be call

        self.show()

    @pyqtSlot()
    def on_click(self):             
        # when the button connecting with this function is clicked, this function are called
        print('Example button click')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())





