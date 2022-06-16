B_NAME = echo env pwd

B_NAME_PATH = $(foreach wrd,$(B_NAME),./bin/$(wrd))

BIN_DIR = ./bin

B_DIR = ./builtins_src/

B_FOLDER:= $(foreach wrd,$(B_NAME),$(B_DIR)$(wrd))

B_MAKE_COMMAND = $(foreach wrd,$(B_FOLDER),make -C $(wrd);)

B_MAKE_CLEAN_COMMAND = $(foreach wrd,$(B_FOLDER),make -C $(wrd) clean;)

B_MAKE_FCLEAN_COMMAND = $(foreach wrd,$(B_FOLDER),make -C $(wrd) fclean;)

all: $(B_NAME_PATH)

$(B_NAME_PATH): $(B_FOLDER)
	mkdir -p $(@D)
	$(B_MAKE_COMMAND)

clean:
	rm -f -r $(BIN_DIR)
	$(B_MAKE_CLEAN_COMMAND)

fclean: clean
	$(B_MAKE_FCLEAN_COMMAND)
re: fclean all
