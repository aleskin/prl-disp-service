CONFIG += qtestlib
QT = xml core

include(CVmDirectoriesTest.deps)

HEADERS += CVmDirectoriesTest.h

SOURCES += CVmDirectoriesTest.cpp

# It is important to have "File Info" embedded in the
# windows binaries - which means we need windows resource file
win32:RC_FILE = $$SRC_LEVEL/Tests/UnitTests.rc
