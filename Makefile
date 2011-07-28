TARGET = fss
MODE   = g01
OBJS   = main.obj # $(TARGET).obj

.PHONY : default build doc ALL

default : build doc

build : ALL

doc :
	doxygen

INCPATH    = ../z_tools/guigui01/
include ../z_tools/command.txt
include ../z_tools/com_mak.txt
