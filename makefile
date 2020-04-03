all:
	gcc -O3 -o gpad-daemon gpad-daemon.c gamepad.c -framework Foundation -framework IOKit `pkg-config --libs libzmq`
	clang -dynamiclib -std=gnu99 -O3 iohid_wrap.m -current_version 1.0 -compatibility_version 1.0 -lobjc -framework Foundation -framework AppKit -framework CoreFoundation `pkg-config --libs libzmq` -o iohid_wrap.dylib

