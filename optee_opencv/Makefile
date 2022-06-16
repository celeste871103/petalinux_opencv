export V ?= 0

OUTPUT_DIR := $(CURDIR)/out

OPENCV_LIST := $(subst /,,$(dir $(wildcard */Makefile)))

.PHONY: all
all: opencvs prepare-for-rootfs

.PHONY: clean
clean: opencvs-clean prepare-for-rootfs-clean

opencvs:
	@for opencv in $(OPENCV_LIST); do \
		$(MAKE) -C $$opencv CROSS_COMPILE="$(HOST_CROSS_COMPILE)" || exit 1; \
	done

opencvs-clean:
	@for opencv in $(OPENCV_LIST); do \
		$(MAKE) -C $$opencv clean || exit 1; \
	done

prepare-for-rootfs: opencvs
	@echo "Copying opencv CA and TA binaries to $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)
	@mkdir -p $(OUTPUT_DIR)/ta
	@mkdir -p $(OUTPUT_DIR)/ca
	@for opencv in $(OPENCV_LIST); do \
		if [ -e $$opencv/host/optee_$$opencv ]; then \
			cp -p $$opencv/host/optee_$$opencv $(OUTPUT_DIR)/ca/; \
		fi; \
		cp -pr $$opencv/ta/*.ta $(OUTPUT_DIR)/ta/; \
	done

prepare-for-rootfs-clean:
	@rm -rf $(OUTPUT_DIR)/ta
	@rm -rf $(OUTPUT_DIR)/ca
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR) || test ! -e $(OUTPUT_DIR)
