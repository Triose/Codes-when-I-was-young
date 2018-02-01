import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QPushButton, QWidget, \
        QAction, QTabWidget, QVBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QMainWindow):

    def __init__(self):
        super().__init__()
        self.title = "PyQt5 tabs"
        self.left, self.top = 0, 0
        self.width, self.height = 300, 200
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.table_widget = MyTableWidget(self)
        self.setCentralWidget(self.table_widget)

        self.show()

class MyTableWidget(QWidget):

    def __init__(self, parent):
        super(QWidget, self).__init__(parent)
        #self.layout = QVBoxLayout(self)     # This line has a problem which we could solve by removing the 'self' in the parentheses
        self.layout = QVBoxLayout()
        
        self.tabs = QTabWidget()
        self.tab1 = QWidget()
        self.tab2 = QWidget()
        self.tabs.resize(300, 300)

        self.tabs.addTab(self.tab1, "Tab 1")
        self.tabs.addTab(self.tab2, "Tab 2")

        self.tab1.layout = QVBoxLayout(self)
        self.pushButton1 = QPushButton("PyQt5 button")
        self.tab1.layout.addWidget(self.pushButton1)
        self.tab1.setLayout(self.tab1.layout)

        # self.pushButton1.clicked.connect(self.on_click)
        self.layout.addWidget(self.tabs)
        self.setLayout(self.layout)

    # I cannot figure out what the following function intends to do
    @pyqtSlot()
    def on_click(self):
        print()
        # And also, in the next line, python interpreter will cast an Attribute Error, if I connect this method with pushButton1
        # AttributeError: 'MyTableWidget' object has no attribute 'tableWidget'
        for currentQTableWidgetItem in self.tableWidget.selectedItems():
            print(currentQTableWidgetItem.row(), currentQTableWidgetItem.column(), currentQTableWidgetItem.text())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())

# To add a table to a window, we create a new class:
# class MyTableWidget(QWidget)

# We initialize the tab screen by creating a QTabWidget and two QWidgets for tabs
# self.tabs = QTabWidget()
# self.tab1 = QWidget()
# self.tab2 = QWidget()
# self.tabs.resize(300, 200)

# Then we add these tabs to the tab widget:
# self.tabs.addTab(self.tab1, "Tab 1")
# self.tabs.addTab(self.tab2, "Tab2")

# The contents of a tab are created by:
# self.tab1.layout = QVBoxLayout()
# selfpushButton1 = QPushButton("PyQt5 button")
# self.tab1.layout.addWidget(self.pushButton1)
# self.tab1.setLayout(self.tab1.layout)

# Finally we add the tabs to the widget:
# self.layout.addWidget(self.tabs)
# self.setLayout(self.layout)

# Don't forget to add your custom tab widget to the window:
# self.table_widget = MyTableWidget(self)
# self.setCentraWidget(self.table_widget)

# This capter of toturial is really low quanlity

