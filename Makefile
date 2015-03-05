#sunixy toolkit top Makefile
SUB_DIR=./list/

default:usr

usr:
	@for n in $(SUB_DIR); do $(MAKE) -C $$n; done
clean:
	@for n in $(SUB_DIR); do $(MAKE) -C $$n clean; done
test:
	@for n in $(SUB_DIR); do $(MAKE) -C $$n test; done

