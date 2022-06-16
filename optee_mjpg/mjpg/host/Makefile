CC      ?= $(CROSS_COMPILE)gcc
LD      ?= $(CROSS_COMPILE)ld
AR      ?= $(CROSS_COMPILE)ar
NM      ?= $(CROSS_COMPILE)nm
OBJCOPY ?= $(CROSS_COMPILE)objcopy
OBJDUMP ?= $(CROSS_COMPILE)objdump
READELF ?= $(CROSS_COMPILE)readelf

OBJS = main.o
SRCOBJS = utils.o
PLUGINS_INPUT_SRC = input_uvc/
PLUGINS_INPUT_UVC_OBJ = dynctrl.o input_uvc.o v4l2uvc.o
PLUGINS_OUTPUT_OBJ = output_file.o
PLUGINS_OUTPUT_SRC = output_file/
#PLUGINS_O_FILE_OBJ = output_file.o httpd.o
#PLUGINS_O_FILE_SRC = output_file/

PLUGINS_INPUT_OBJS = $(addprefix $(PLUGINS_INPUT_SRC), $(PLUGINS_INPUT_UVC_OBJ))
PLUGINS_OUTPUT_OBJS = $(addprefix $(PLUGINS_OUTPUT_SRC), $(PLUGINS_OUTPUT_OBJ))
#PLUGINS_O_FILE_OBJS = $(addprefix $(PLUGINS_O_FILE_SRC), $(PLUGINS_O_FILE_OBJ))
CFLAGS += -Wall -I../ta/include -I$(TEEC_EXPORT)/include -I./include
CFLAGS +=  -Iinput_uvc/ -I./input_uvc/ -Ioutput_http/ -I./output_http/ -Ioutput_file/ -I./output_file/ -Ijpeglib/ -I./jpeglib/

#Add/link other required libraries here
LDADD += -lteec -L$(TEEC_EXPORT)/lib
INCLUDE_PATH = -I.
TEST_TARGET = main
TEST_SRC = main.c
LDFLAGS= -lm -pthread
BINARY = optee_mjpg
.PHONY: all
all: $(BINARY)
	
$(BINARY): $(OBJS) $(SRCOBJS) $(PLUGINS_INPUT_OBJS) $(PLUGINS_OUTPUT_OBJS) 
	$(CC) -o $@ $^ $(LDFLAGS) $(LDADD) 


$(PLUGINS_INPUT_SRC)%.o: $(PLUGINS_INPUT_SRC)%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(PLUGINS_OUTPUT_SRC)%.o: $(PLUGINS_OUTPUT_SRC)%.c
		$(CC) $(CFLAGS) -c $< -o $@

#$(PLUGINS_O_FILE_SRC)%.o: $(PLUGINS_O_FILE_SRC)%.c
#		$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(BINARY) $(SRCOBJS) $(PLUGINS_INPUT_OBJS) $(PLUGINS_OUTPUT_OBJS) 

