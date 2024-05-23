all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C console
clean:
	$(MAKE) clean mySimpleComputer
	$(MAKE) clean console
