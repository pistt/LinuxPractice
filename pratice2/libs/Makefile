CC	:= g++
CFLAGS	:= -std=c++17 -fPIC -shared -o
OBJS	:= $(wildcard *.cpp)
TARGET	:= $(patsubst %.cpp,lib%.so,$(OBJS))

all:$(TARGET)
$(TARGET):lib%.so:%.cpp
	$(CC) $(CFLAGS) $@ $<

.PHONY:clean
clean:
	-rm -rf $(TARGET)
