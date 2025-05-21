com=gcc
flag=-Wall

dtest=tests
dinc=include
dsrc=src
dbuild=build


dotc := $(wildcard $(dsrc)/*.c)
doto := $(patsubst $(dsrc)/%.c, $(dbuild)/%.o, $(dotc))

$(dbuild)/%.o: $(dsrc)/%.c
	$(com) $(flag) -I$(dinc) -I"extern/libuv/include" -c $< -o $@

unix-bne: $(doto)
	$(com) $(flag) $^ -o $@ -L"extern/libuv" -luv
	$(shell ./unix-bne)


clean:
	$(shell rm -r $(dbuild)/*)
	@echo "foi"
