MINCDIR = /projects/mice/share/arch/linux64
QUARTERDIR = /usr/local

COINLIBS = $$system(coin-config --ldflags)
COININCLUDE = $$system(coin-config --includedir)

CONFIG += qt debug
QT += opengl


INCLUDEPATH += $$COININCLUDE
LIBS += $$COINLIBS

!macx {
 	LIBS += -lCoin
 	LIBS += -L$$(QUARTERDIR) -lQuarter
    INCLUDEPATH += $$(MINCDIR)/include
    INCLUDEPATH += $$(QUARTERDIR)/include
 	LIBS += -L$$(MINCDIR)/lib/ -lbicpl -lvolume_io2 -lminc2
}

macx {
	LIBS += -Wl,-framework -Wl,Quarter
	LIBS += -L$$(MINCDIR)/lib -lbicpl -lvolume_io2 -lminc2
	INCLUDEPATH += $$(MINCDIR)/include
}

INCLUDEPATH += /usr/local/include

FORMS = colourBarForm.ui \
		resourceForm.ui \
		geometryProps.ui
		
HEADERS = MainWindow.h \
          ColourBarForm.h \
          BrainQuarter.h \
          TreeItem.h \
          TreeModel.h \
          GeometryScene.h \
          ResourceForm.h \
          GeometryNode.h
          
SOURCES = MainWindow.cpp \
          ColourBarForm.cpp \
          BrainQuarter.cpp \
          TreeItem.cpp \
          TreeModel.cpp \
          ResourceForm.cpp \
          GeometryScene.cpp \
          GeometryNode.cpp \
          main.cpp
