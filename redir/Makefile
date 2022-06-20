R_NAME = in_file in_prompt out_append out_trunc

R_NAME_PATH = $(foreach wrd,$(R_NAME),./bin/$(wrd))

BIN_DIR = ./bin

R_DIR = ./

R_FOLDER:= $(foreach wrd,$(R_NAME),$(R_DIR)$(wrd))

R_MAKE_COMMAND = $(foreach wrd,$(R_FOLDER),make -C $(wrd);)

R_MAKE_CLEAN_COMMAND = $(foreach wrd,$(R_FOLDER),make -C $(wrd) clean;)

R_MAKE_FCLEAN_COMMAND = $(foreach wrd,$(R_FOLDER),make -C $(wrd) fclean;)

all: $(R_NAME_PATH)

$(R_NAME_PATH): $(R_FOLDER)
	mkdir -p $(@D)
	$(R_MAKE_COMMAND)

clean:
	rm -f -r $(BIN_DIR)
	$(R_MAKE_CLEAN_COMMAND)

fclean: clean
	$(R_MAKE_FCLEAN_COMMAND)

re: fclean all