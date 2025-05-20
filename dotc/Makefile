com=gcc
flag=-Wall

dtest=tests
dinc=include
dsrc=src
dbuild=build


dotc := $(wildcard $(dsrc)/*.c)
doto := $(patsubst $(dsrc)/%.c, $(dbuild)/%.o, $(dotc))

$(dbuild)/%.o: $(dsrc)/%.c
	$(com) $(flag) -I$(dinc) -c $< -o $@

n: $(doto)
	$(com) $(flag) $^ -o $@

clean:
	$(shell rm -r $(dbuild)/*)
	@echo "foi"
