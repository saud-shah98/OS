cc = g++
CFLAGS =
OBJFILES = dispatcher.o main.o pcb.o process.o scheduler.o
TARGET = Program

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET) *~