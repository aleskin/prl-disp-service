LIBTARGET = Transponster
PROJ_FILE = $$PWD/Transponster.pro
QTCONFIG = core xml
!include(../../Build/qmake/staticlib.pri): error(include error)

INCLUDEPATH *= $$PWD

include($$SRC_LEVEL/XmlModel/XmlModel.pri)
