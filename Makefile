#######################################
# Makefile PBM                        #
#                                     #
# E.B.                                #
#######################################


objects = scharr_x_test.o Util.o

scharr_x_test : $(objects)
	gcc -o scharr_x_test $(objects) -lm

.PHONY : clean
clean :
	-rm -f *.o


