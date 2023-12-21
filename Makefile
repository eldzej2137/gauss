all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	bin/gauss dane/A3 dane/b3
	bin/gauss dane/A4 dane/B4
	bin/gauss dane/A5 dane/B5
	bin/gauss dane/A6 dane/B6
	bin/gauss dane/A7 dane/B7
	bin/gauss dane/A8 dane/B8
	bin/gauss dane/A9 dane/B9
