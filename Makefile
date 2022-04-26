out:lib
	gcc -g main.c -obin/ttt -Iinclude -Llib -lttt


lib:obj
	ar cr libttt.a *.o
	mv libttt.a lib/

obj:
	gcc -c src/*.c -Iinclude
