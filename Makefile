PORT = 3
BAUD = 38400

serial_test: serial_test.hex
	@cmd_ASA_loader -p $(PORT) -h $<
	@terminal -p $(PORT) -b $(BAUD)

%.hex:
	make -f m128.make $@
