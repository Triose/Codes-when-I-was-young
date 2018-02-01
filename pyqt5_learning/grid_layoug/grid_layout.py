# In PyQt5, grid layout is called QGridLayout
# Widgets can be added to a grid in both the horizontal and vertical direction

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QGroupBox, QDialog, QVBoxLayout, QGridLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QDialog):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 layout'
        self.geo = (10, 10, 320, 100)

        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(*self.geo) 

        self.createGridLayout()

        windowLayout = QVBoxLayout()
        windowLayout.addWidget(self.horizontalGroupBox)
        self.setLayout(windowLayout)

        self.show()

    def createGridLayout(self):
        # We create the grid with a title and set the size
        self.horizontalGroupBox = QGroupBox("Grid")
        layout = QGridLayout()
        layout.setColumnStretch(1, 4)
        layout.setColumnStretch(2, 4)

        # fill the grid with QPushButtons
        for i in range(3):
            for j in range(3):
                layout.addWidget(QPushButton("{}".format(str(i * 3 + j + 1))), i, j)
        
        self.horizontalGroupBox.setLayout(layout)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())





