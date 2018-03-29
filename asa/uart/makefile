# makefile test for hello program
#written by Emdoor
CC = gcc
COM = 2
AVRDUDE = C:/tools/WinAVR-20100110/bin/avrdude

TEST_TAR += test.exe
TEST_SRC += test.c
TEST_SRC += ../../revlib/ASA/ASA_UARTS.c
TEST_SRC += ../../revlib/ASA/buffer.c

test:
	$(CC) $(TEST_SRC) -o $(TEST_TAR)

s_rec:
	make s_rec.m88.hex -f m88.make
	$(AVRDUDE) -c stk500 -p m88 -b 115200 -P COM$(COM) -e -U flash:w:"s_rec.m88.hex":i

m_rec:
	make m_rec.m128.hex -f M128.make
	cmd_ASA_loader -p $(COM) -h m_rec.m128.hex
	terminal -p $(COM)
