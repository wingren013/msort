all: dispatcher

CCFLAGS += -D DEVICE=$(DEVICE)

tt:
	make -C ../TurboTranspose-master clean
	make -C ../TurboTranspose-master
lz4:
	make -C ../lz4-lib clean
	make -C ../lz4-lib

dispatcher: tt lz4
	make -C Msort/ clean
	make -C Msort/
	rm -f dispatcher
	clang -o dispatcher -m64 -lm -pthread *.c Msort/msort.a ../TurboTranspose-master/transpose.o ../TurboTranspose-master/transpose_sse.o ../lz4-lib/liblz4.a -O3 -I ../TurboTranspose-master -I ../lz4-lib -I Msort/includes/

quick:
	make -C Msort/ clean
	make -C Msort/
	rm -f dispatcher
	clang -o dispatcher -m64 -lm -pthread *.c ../TurboTranspose-master/transpose.o ../TurboTranspose-master/transpose_sse.o ../lz4-lib/liblz4.a -O3 -I ../TurboTranspose-master -I ../lz4-lib

clean:
	rm -f dispatcher
	make -C ../TurboTranspose-master clean
	make -C ../lz4-lib clean

re: clean all
