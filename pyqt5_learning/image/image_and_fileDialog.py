# Now, we could use what we have learnt to create a simple program displaing an specific image

import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QWidget, QInputDialog, QLineEdit, QFileDialog, QLabel
from PyQt5.QtGui import QIcon, QPixmap

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = "PyQt5 image display"
        self.geo = (10, 10, 640, 480)
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(*self.geo)

        # Create widget & get file name
        label = QLabel(self)
        picUrl = self.getPicUrl()
        if not picUrl:
            sys.exit()
        pixmap = QPixmap(picUrl)
        label.setPixmap(pixmap)
        self.resize(pixmap.width(), pixmap.height())
        
        self.show()

    def getPicUrl(self):
        options = QFileDialog.Options()
        options |= QFileDialog.DontUseNativeDialog
        filename, _ = QFileDialog.getOpenFileName(self, "Select the image you want", "", "Jpeg file(*.jpeg);;Jpg file(*.jpg)", options = options) 
        if filename: 
            return filename


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())




