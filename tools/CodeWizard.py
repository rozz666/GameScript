# GameScript
#
# Copyright (c) 2011 Rafal Przywarski
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#
import sys
import os
from PyQt4 import QtGui, QtCore

class License:
    @staticmethod
    def getText():
        license = "// GameScript\n"
        license += "//\n"
        license += "// Copyright (c) 2011 Rafal Przywarski\n"
        license += "//\n"
        license += "// Distributed under the Boost Software License, Version 1.0.\n"
        license += "// (See accompanying file LICENSE_1_0.txt or copy at\n"
        license += "// http://www.boost.org/LICENSE_1_0.txt)\n"
        license += "//\n"
        return license

class ClassQualifiedName:
    def __init__(self, qualifiedName):
        self._ids = qualifiedName.split(".")
    def getNamespaces(self):
        return self._ids[0:-1]
    def getName(self):
        return self._ids[-1]
    def getHeaderGuard(self):
        return "_".join(self._ids).upper() + "_HPP"
    def getHeaderPath(self):
        return "/".join(self._ids) + ".hpp"
    def getSourcePath(self):
        return "/".join(self._ids) + ".cpp"
    def getUnitTestPath(self):
        return self._ids[0] + "/test/unit/" + "/".join(self._ids[1:]) + ".cpp"
    def getMockPath(self):
        return self._ids[0] + "/test/unit/" + "/".join(self._ids[1:]) + ".hpp"
    def getFixtureName(self):
        return "_".join(self._ids)

class Wizard:
    def writeFile(self, fileName, text):
        path = fileName.rpartition("/")[0]
        QtCore.QDir().mkpath(path)
        f = QtCore.QFile(fileName)
        f.open(QtCore.QIODevice.WriteOnly)
        f.writeData(text)
        f.close()

class ClassWizard(Wizard):
    def createHeaderFile(self, classQName):
        namespaces = classQName.getNamespaces()
        guard = classQName.getHeaderGuard()
        className = classQName.getName()

        text = License.getText()
        text += "#ifndef " + guard + "\n#define " + guard + "\n\n"
        text += "#include <boost/shared_ptr.hpp>\n\n"
        for id in namespaces:
            text += "namespace " + id + "\n{\n"
        text += "\nclass " + className + "\n{\npublic:\n};\n\n"
        text += "typedef boost::shared_ptr<" + className + "> Shared" + className + ";\n\n"
        for id in namespaces:
            text += "}\n"
        text += "#endif /* " + guard + " */\n"
        self.writeFile(classQName.getHeaderPath(), text)

    def createSourceFile(self, classQName):
        namespaces = classQName.getNamespaces()
        text = License.getText()
        text += "#include <" + classQName.getHeaderPath() + ">\n\n"
        for id in namespaces:
            text += "namespace " + id + "\n{\n"
        for id in namespaces:
            text += "}\n"
        self.writeFile(classQName.getSourcePath(), text)

    def createUnitTestFile(self, classQName):
        fixtureName = classQName.getFixtureName()
        text = License.getText()
        text += "#include <" + classQName.getHeaderPath() + ">\n"
        text += "#include <gmock/gmock.h>\n"
        text += "\n"
        text += "using namespace testing;\n"
        text += "\n"
        text += "struct " + fixtureName + " : testing::Test\n"
        text += "{\n"
        text += "};\n"
        text += "\n"
        text += "TEST_F(" + fixtureName + ", firstTest)\n"
        text += "{\n"
        text += "}\n"
        self.writeFile(classQName.getUnitTestPath(), text)

    def createClass(self, strName):
        classQName = ClassQualifiedName(strName)
        self.createHeaderFile(classQName)
        self.createSourceFile(classQName)
        self.createUnitTestFile(classQName)

class InterfaceWizard(Wizard):
    def createHeaderFile(self, classQName):
        namespaces = classQName.getNamespaces()
        guard = classQName.getHeaderGuard()
        className = classQName.getName()

        text = License.getText()
        text += "#ifndef " + guard + "\n#define " + guard + "\n\n"
        text += "#include <boost/shared_ptr.hpp>\n\n"
        for id in namespaces:
            text += "namespace " + id + "\n{\n"
        text += "\nclass " + className + "\n"
        text += "{\n"
        text += "public:\n"
        text += "    virtual ~" + className + "() { }\n"
        text += "protected:\n"
        text += "    " + className + "() { }\n"
        text += "    " + className + "(const " + className + "& ) { }\n"
        text += "    " + className + "& operator=(const " + className + "& ) { return *this; }\n"
        text += "};\n\n"
        text += "typedef boost::shared_ptr<" + className + "> Shared" + className + ";\n\n"
        for id in namespaces:
            text += "}\n"
        text += "#endif /* " + guard + " */\n"
        self.writeFile(classQName.getHeaderPath(), text)

    def createInterface(self, strName):
        classQName = ClassQualifiedName(strName)
        self.createHeaderFile(classQName)

class MockWizard(Wizard):
    def createMockFile(self, classQName, origClassQName):
        namespaces = classQName.getNamespaces()
        guard = classQName.getHeaderGuard()
        className = classQName.getName()

        text = License.getText()
        text += "#ifndef " + guard + "\n#define " + guard + "\n\n"
        text += "#include <" + origClassQName.getHeaderPath() + ">\n"
        text += "#include <gmock/gmock.h>\n\n"
        for id in namespaces:
            text += "namespace " + id + "\n{\n"
        text += "\nstruct " + className + " : " + origClassQName.getName() + "\n"
        text += "{\n"
        text += "};\n\n"
        text += "typedef boost::shared_ptr<" + className + "> Shared" + className + ";\n\n"
        for id in namespaces:
            text += "}\n"
        text += "#endif /* " + guard + " */\n"
        self.writeFile(classQName.getMockPath(), text)

    def createMock(self, strName):
        classQName = ClassQualifiedName(strName + "Mock")
        origClassQName = ClassQualifiedName(strName)
        self.createMockFile(classQName, origClassQName)

class FactoryWizard(Wizard):
    def createFactory(self, strName):
        classQName = ClassQualifiedName(strName)
        ClassWizard().createHeaderFile(classQName)
        ClassWizard().createSourceFile(classQName)
        MockWizard().createMock(strName)


class CodeWizard(QtGui.QMainWindow):

    def __init__(self):
        super(CodeWizard, self).__init__()
        self.initUi()

    def initUi(self):

        createClassAction = QtGui.QAction("Create Class", self)
        createClassAction.setStatusTip("Create a class with a test suite")
        createInterfaceAction = QtGui.QAction("Create Interface", self)
        createInterfaceAction.setStatusTip("Create an interface")
        createMockAction = QtGui.QAction("Create Mock", self)
        createMockAction.setStatusTip("Create a mock")
        createFactoryAction = QtGui.QAction("Create Factory", self)
        createFactoryAction.setStatusTip("Create a factory")
        self.connect(createClassAction, QtCore.SIGNAL("triggered()"), self.createClass)
        self.connect(createInterfaceAction, QtCore.SIGNAL("triggered()"), self.createInterface)
        self.connect(createMockAction, QtCore.SIGNAL("triggered()"), self.createMock)
        self.connect(createFactoryAction, QtCore.SIGNAL("triggered()"), self.createFactory)

        self.toolbar = self.addToolBar("Main")
        self.toolbar.addAction(createClassAction)
        self.toolbar.addAction(createInterfaceAction)
        self.toolbar.addAction(createMockAction)
        self.toolbar.addAction(createFactoryAction)
        self.toolbar.setOrientation(QtCore.Qt.Vertical)

        self.setSizePolicy(QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Minimum))
        self.setWindowTitle('Code Wizard')

    def createClass(self):
        classQualifiedName, ok = QtGui.QInputDialog.getText(self, 'Create Class', 'Enter class name:')
        if not ok:
            return
        ClassWizard().createClass(str(classQualifiedName))

    def createInterface(self):
        interfaceQualifiedName, ok = QtGui.QInputDialog.getText(self, 'Create Interface', 'Enter interface name:')
        if not ok:
            return
        InterfaceWizard().createInterface(str(interfaceQualifiedName))

    def createMock(self):
        mockQualifiedName, ok = QtGui.QInputDialog.getText(self, 'Create Mock', 'Enter mock name:')
        if not ok:
            return
        MockWizard().createMock(str(mockQualifiedName))

    def createFactory(self):
        factoryQualifiedName, ok = QtGui.QInputDialog.getText(self, 'Create Factory', 'Enter factory name:')
        if not ok:
            return
        FactoryWizard().createFactory(str(factoryQualifiedName))


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    app.setWindowIcon(QtGui.QIcon(os.path.dirname(sys.argv[0]) + "/wizard.png"))
    ex = CodeWizard()
    ex.show()
    sys.exit(app.exec_())