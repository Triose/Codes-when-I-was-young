# Widgets can be added on an absolute position using the move(x, y) method.

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow, QLabel
from PyQt5.QtGui import QIcon

class App(QMainWindow):
    
    def __init__(self):
        super().__init__()
        self.title = "PyQt absolute positioning"
        self.left, self.top = 10, 10
        self.width, self.height = 440, 280
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        
        label = QLabel('Fir', self)
        label.move(50, 50)

        label2 = QLabel('Sec', self)
        label2.move(100, 100)

        label3 = QLabel('Trd', self)
        label3.move(150, 150)

        label4 = QLabel('4nd', self)
        label4.move(200, 200)

        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())



