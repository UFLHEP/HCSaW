CXX=g++
CC=gcc
CFLAGS=-O2 -Wall
LDFLAGS=-Llib
PRFFLAGS=-lProof
THRDFLAGS=-lThread
IN=-I$(ROOTSYS)/include/root
INS=-I../../Higgs_CS_and_Width_Fermiophobic/include
INSS=-I../../Higgs_CS_and_Width_Fermiophobic/src

CFLAGS += `root-config --cflags`
LIBS += `root-config --glibs`


OBJSS=validationTest.o
OBJSSS=validationTest_pdf.o
OBJSSSS=validationTest_scale.o
OBJSSSSS=validationTest_BR.o

.PHONY: clean all main test

all: validateBR

validateBR: validationTest_BR.o
	$(CXX) -o validationTest_BR.exe $(OBJSSSSS) $(LIBS)

clean:
	@rm *.o *.exe *~ 

new:
	@rm *.root *.eps *.gif *~

##############RULES##############
.cc.o:
	$(CXX) $(CFLAGS) $(IN) $(INS) $(INSS) -c $<
.cpp.o:
	$(CXX) $(CFLAGS) $(IN) $(INS) $(INSS) -c $<


