CC			= gcc
CXX			= g++
CFLAGS		= -Wall 
CXXFLAGS	=
CPPFLAGS	= 
LDFLAGS 	=  
LIBS		= 

TARGET		= $(notdir $(shell pwd))
SRCDIR		= ./src
OBJDIR		= ./build
INCDIR		= ./include

SUFFIXES	= .c .cpp .asm

SRCS		= $(foreach suffix, $(SUFFIXES), $(wildcard $(SRCDIR)/*$(suffix)))
OBJS		= $(addsuffix .o,$(addprefix $(OBJDIR)/, $(notdir $(basename $(SRCS) ) ) ) )

#$(warning $(SRCS))

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(warning $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(warning $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.asm
	@mkdir -p $(OBJDIR)
	$(warning $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

test:$(TARGET)
	test/test.sh

.PHONY: all clean