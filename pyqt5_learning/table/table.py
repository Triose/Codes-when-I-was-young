# To added a table, you will need to import QTableWidget and QTableWidgetItem
# EG: A table is created with:
#   self.tableWidget = QTableWidget()
#   self.tableWidget.setRowCount(rowCount)    # set row count
#   self.tableWidget.setColumnCount(ColCount) # set Column count
# EG: To add individual cells:
#   self.tableWidget.setItem(X, Y, QTableWidgetItem("Text")

import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QWidget, QAction, \
        QTableWidget, QTableWidgetItem, QVBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 table'
        self.left, self.top = 0, 0
        self.width, self.height = 300, 200
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.createTable()
        
        # Add box layout to hold the table
        self.layout = QVBoxLayout()
        self.layout.addWidget(self.tableWidget)
        self.setLayout(self.layout)

        self.show()

    def createTable(self):
        # Create table
        self.tableWidget = QTableWidget()
        self.tableWidget.setRowCount(4)
        self.tableWidget.setColumnCount(2)

        # The code in the tutorial is somehow awkward, so I replaced it with below
        for i in range(4): 
            for j in range(2):
                self.tableWidget.setItem(i, j, QTableWidgetItem("cell ({}, {})".format(i, j)))

        self.tableWidget.move(0, 0)
        self.tableWidget.doubleClicked.connect(self.on_click)

    @pyqtSlot()
    def on_click(self):
        print()
        for currentQTableWidgetItem in self.tableWidget.selectedItems():
            print(currentQTableWidgetItem.row(), currentQTableWidgetItem.column(), currentQTableWidgetItem.text())
    

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())






