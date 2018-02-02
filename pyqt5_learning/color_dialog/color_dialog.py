




















































































































































































# PyQt5 supports a color picker known as QColorDialog.
# color = QColorDialog.getColor()

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QColorDialog
from PyQt5.QtGui import QIcon, QColor
from PyQt5.QtCore import pyqtSlot

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 color dialog'
        self.left, self.top = 10, 10
        self.width, self.height = 320, 200
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        button = QPushButton('Open color dialog', self)
        button.setToolTip('Opens color dialog')
        button.move(10, 10)
        button.clicked.connect(self.on_click)

        self.show()

    @pyqtSlot()
    def on_click(self):
        # The key code is this line
        self.openColorDialog()

    def openColorDialog(self):
        # Pick a color
        color = QColorDialog.getColor()

        if color.isValid():
            print(color.name())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())

