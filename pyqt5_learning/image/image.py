# Adding an image to PyQt5 window is as simple as creating a label and adding an image to that label
# See the following lines:
# label = QLabel(self)
# pixmap = QPixmap('image.jpeg')
# label.setPixmap(pixmap)

# self.resize(pixmap.width(), pixmap.height())  # optional-resize window to image size

# These are required imports:
# from PyQt5.QtWidgets import QApplication, QWidget, QLabel
# from PyQt5.QtGui import QIcon, QPixmap

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel
from PyQt5.QtGui import QIcon, QPixmap

class App(QWidget):
    
    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 image'
        self.geo = 10, 10, 640, 480
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(*self.geo)

        # Create Widget
        label = QLabel(self)
        pixmap = QPixmap('test.jpeg')
        label.setPixmap(pixmap)
        self.resize(pixmap.width(), pixmap.height())
        
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
        
    







