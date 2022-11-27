CC			= gcc
AS			= as
CXX			= g++
CFLAGS		= -Wall 
CXXFLAGS	=
CPPFLAGS	= 
LDFLAGS 	= -static
LIBS		= 

TARGET		= $(notdir $(shell pwd))

SRCS		= $(TARGET).s
OBJS		= $(TARGET).o

all:$(TARGET)

$(TARGET):$(OBJS)
	@ld -o $@ $(CPPFLAGS) $(LDFLAGS) $^

$(OBJS):$(SRCS)
	@as -o $@ $(CFLAGS) $(CPPFLAGS)  $<

clean:
	@rm $(OBJS) $(TARGET)

.PHONY: clean all