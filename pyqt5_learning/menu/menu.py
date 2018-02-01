# The top menu can be created with the method menuBar()
# Sub menus are added with addMenu(name):
# mainMenu = self.menuBar()
# fileMenu = mainMenu.addMenu('File')

# Individual buttons can be added to the menus like this:
# exitButton = QAction(QIcon('exit24.png', 'Exit', self)
# exitButton.setShortcut('Ctrl+Q')
# exitButton.setStatusTip('Exit application')
# exitButton.triggered.connect(self.close)
# fileMenu.addAction(exitButton)

import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QWidget, QPushButton, QAction
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QMainWindow):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 menu'
        self.left, self.top = 10, 10
        self.width, self.height = 640, 400
        self.initUI()
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        # defined a main menu and some sub menu of it
        mainMenu = self.menuBar()
        fileMenu = mainMenu.addMenu('File')
        editMenu = mainMenu.addMenu('Edit')
        viewMenu = mainMenu.addMenu('View')
        searchMenu = mainMenu.addMenu('Search')
        toolsMenu = mainMenu.addMenu('Tools')
        helpMenu = mainMenu.addMenu('Help')

        # defined a exit button in the sub manu called 'File'
        exitButton = QAction(QIcon('exit24.png'), 'Exit', self)
        exitButton.setShortcut('Ctrl+Q')
        exitButton.setStatusTip('Exit application')
        exitButton.triggered.connect(self.close)
        fileMenu.addAction(exitButton)

        self.show()

if __name__ == '__main__':
   app = QApplication(sys.argv)
   ex = App()
   sys.exit(app.exec_())




