import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QGroupBox, QDialog, QVBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QDialog):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 layout'
        self.geo = (10, 10, 320, 100)   # left, top, width, height
        
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(*self.geo)      # define the size of a window is a troublesome process, we could replace it by this
        
        self.createHorizontalLayout()

        windowLayout = QVBoxLayout()
        windowLayout.addWidget(self.horizontalGroupBox)
        self.setLayout(windowLayout)

        self.show()

    def createHorizontalLayout(self):
        # We create a box with a title and a horizontal layout:
        self.horizontalGroupBox = QGroupBox("What is your favorite color?")
        layout = QHBoxLayout()

        # We create widgets(QPushButtons) and add them the the layout:
        buttonBlue = QPushButton("Blue", self)
        buttonBlue.clicked.connect(self.on_click)
        layout.addWidget(buttonBlue)

        buttonRed = QPushButton("Red", self)
        buttonRed.clicked.connect(self.on_click)
        layout.addWidget(buttonRed)

        buttonGreen = QPushButton("Green", self)
        buttonGreen.clicked.connect(self.on_click)
        layout.addWidget(buttonGreen)

        # We set the title-box to contain the horizontal layout:
        self.horizontalGroupBox.setLayout(layout)

    @pyqtSlot()
    def on_click(self):
        print("PyQt5 button click")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())











