DIR = `pwd`
NATIVES = ../../natives/lib
TARGETS := bcm_host egl sdl x11

.PHONY: all clean move

clean:
	@$(foreach DIR,$(TARGETS), cd $(DIR); make $@; cd ..;)

all:
	@$(foreach DIR,$(TARGETS), cd $(DIR); make; cd ..;)

move:
	@$(foreach DIR,$(TARGETS), cd $(DIR); make $@; cd ..;)
