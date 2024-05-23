all:
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C console
clean:
	$(MAKE) clean mySimpleComputer
	$(MAKE) clean myTerm 
	$(MAKE) clean console
