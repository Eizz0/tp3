#######################################
# Makefile PBM                        #
#                                     #
# E.B.                                #
#######################################


objects = scharr_y.o Util.o

scharr_y : $(objects)
	gcc -o scharr_y $(objects) -lm

.PHONY : clean
clean :
	-rm -f *.o


