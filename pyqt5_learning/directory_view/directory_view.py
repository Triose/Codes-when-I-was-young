# PyQt can show a directory structure using a QTreeView
# For the treeview to show as a directory tree, we need to set it's modle to a QFileSystemModel instance
# That is achieved by calling the setModel method for the tree instance

import sys
from PyQt5.QtWidgets import QApplication, QFileSystemModel, QTreeView, QWidget, QVBoxLayout
from PyQt5.QtGui import QIcon

class App(QWidget):

    def __init__(self):
        super().__init__()
        self.title = 'PyQt5 file system view'
        self.left, self.top, self.width, self.height = 10, 10, 640, 480
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        self.model = QFileSystemModel()
        self.model.setRootPath("/home")
        self.tree = QTreeView()
        self.tree.setModel(self.model)

        self.tree.setAnimated(False)
        self.tree.setIndentation(20)
        self.tree.setSortingEnabled(True)

        self.tree.setWindowTitle("Dir view")
        self.tree.resize(640, 480)

        windowLayout = QVBoxLayout()
        windowLayout.addWidget(self.tree)
        self.setLayout(windowLayout)

        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())





