run: process_scheduling
	
process_scheduling: process_scheduling.c
	gcc process_scheduling.c -o process_scheduling
	./process_scheduling

setup:
	gcc test1.c -o test1
	gcc test2.c -o test2
	gcc test3.c -o test3
clean:
	rm -f process_scheduling test1 test2 test3
	killall -9 test1
	killall -9 test2
	killall -9 test3
renice:
	gcc renice.c -o renice
	./renice
