## Makefile
# @authro Hirokazu Yokoyama

APP = SerializeSample.app
CXX = g++
LIBS = -L/usr/local/Cellar/boost/1.55.0/lib -lboost_serialization
OBJS = main.o
CFLAG = -I/usr/local/Cellar/boost/1.55.0/include

all: $(APP)

$(APP): $(OBJS)
	$(CXX) $(LIBS) $(CFLAG) $(OBJS) -o $@

.cpp.o:
	$(CXX) -c $< $(LIBS) $(CFLAG)
