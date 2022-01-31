TEMPLATE    = app
QT         += opengl 

INCLUDEPATH +=  /usr/include/glm \
		/Escritorio/ididisco/Model

FORMS += MyForm.ui

HEADERS += MyForm.h Bl2GLWidget.h MyGLWidget.h

SOURCES += main.cpp MyForm.cpp \
        Bl2GLWidget.cpp MyGLWidget.cpp \
        /Escritorio/ididisco/Model/model.cpp
