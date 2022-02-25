media-control-sway: main.c
	gcc main.c -o media-control-sway

install: 
	mv media-control-sway /usr/bin/media-control-sway

uninstall: 
	rm /usr/bin/media-control-sway
