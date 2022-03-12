ALLDIR	= $(LIBDIR)
CC	:= g++
OBJS	:= $(subst .cpp,.o,$(wildcard *.cpp))
LIBDIR	:= ./libs
LIBCPPDIR:=./libs
LIBCPP	:= $(shell ls $(LIBCPPDIR) | grep cpp)
LIBNAME:= $(LIBCPP:%.cpp=%)

test:$(OBJS) CONSTRUCT_LIB
	$(CC) -o $@ $< -L$(LIBDIR) $(LIBNAME:%=-l%)
CONSTRUCT_LIB:
	@ for DIR in $(LIBDIR);\
		do\
			cd $$DIR;\
			$(MAKE);\
			cd ..;\
		done
%.o:%.cpp
	$(CC) -c $^
	

.PHONY:clean
clean:
	rm -rf *.o *.so
	@ for DIR in $(LIBDIR);\
		do\
			cd $$DIR;\
			$(MAKE) clean;\
			cd ..;\
		done

