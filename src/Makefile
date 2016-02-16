GXX = g++
CCFLAGS = -I /usr/include $(INCLUDEDIRS) -std=c++0x
LIBDIR = -L /usr/lib
INCLUDEDIRS = -I ../include/
OBJDIR = ../obj/
LNFLAGS = -lncurses -ltinfo
OBJECTS = Clock.o StateShowTime.o StateSetHour.o StateSetMinutes.o main.o
OBJS = $(addprefix $(OBJDIR), $(OBJECTS))
EXECUTALBE = ../clockSimulator

$(EXECUTALBE): $(OBJS)
	${GXX} $(LIBDIR) -o $@ $^ $(LNFLAGS)
	
$(OBJDIR)%.o : %.cpp
	${GXX} -c -o $@ $< $(CCFLAGS)

clean:
	rm -f ./include/*~ ./include/*% ./include/*# ./include/.#*
	rm -f ./src/*~ ./src/*% ./src/*# ./src/.#*
	rm -f ../obj/*.o

clean-all: clean
	rm -f $(EXECUTALBE)
