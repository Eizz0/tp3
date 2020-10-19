#######################################
# Makefile PBM                        #
#                                     #
# E.B.                                #
#######################################


PROG = scharr_x_y

all : $(PROG)

# Variables for file compilation
CC        =  gcc
CFLAGS    =  -g -Wall
CPPFLAGS  =  -DDEBUG
LDFLAGS   =  -g -lm


scharr_x_y : scharr_x_y.o Util.o

clean :
	@rm -f *.o

cleanall : clean
	@rm -f $(PROG)
