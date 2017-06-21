NAME = msort.a

all:
	mkdir build
	gcc -c srcs/msort.c -o build/msort.o
	gcc -c srcs/msort_helper.c -o build/msort_helper.o
	ar rc $(NAME) build/mosrt.o build/msort_helper.o

clean:
	rm -rf build/
	rm -f $(NAME)

re: clean all
