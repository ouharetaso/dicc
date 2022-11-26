CC			= gcc
AS			= as
CXX			= g++
CFLAGS		= -Wall
CXXFLAGS	=
CPPFLAGS	= 
LDFLAGS 	= -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start
LIBS		= 

TARGET		= $(notdir $(shell pwd))

SRCS		= $(TARGET).s
OBJS		= $(TARGET).o

all:$(TARGET)

$(TARGET):$(OBJS)
	@ld -o $@ $(CPPFLAGS) $(LDFLAGS) $^

$(OBJS):$(SRCS)
	@as -o $@ $<

clean:
	@rm $(OBJS) $(TARGET)

.PHONY: clean all