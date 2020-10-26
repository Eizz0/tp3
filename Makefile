#######################################
# Makefile PBM                        #
#                                     #
# E.B.                                #
#######################################


objects = scharr_x.o Util.o

scharr_x : $(objects)
	gcc -o scharr_x $(objects) -lm

.PHONY : clean
clean :
	-rm -f *.o


