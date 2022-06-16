CC      ?= $(CROSS_COMPILE)g++
LD      ?= $(CROSS_COMPILE)ld
AR      ?= $(CROSS_COMPILE)ar
NM      ?= $(CROSS_COMPILE)nm
OBJCOPY ?= $(CROSS_COMPILE)objcopy
OBJDUMP ?= $(CROSS_COMPILE)objdump
READELF ?= $(CROSS_COMPILE)readelf

OBJS = main.o

CFLAGS += -Wall -I../ta/include -I$(TEEC_EXPORT)/include -I./include 
#Add/link other required libraries here
LDADD += -lteec -L$(TEEC_EXPORT)/lib -lstdc++ 
LDFLAGS += -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc
BINARY = optee_opencv

.PHONY: all
all: $(BINARY)

$(BINARY): $(OBJS)
	$(CC) -o $@ $< $(LDFLAGS) $(LDADD) 

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
