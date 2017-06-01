CC_FLAGS = 


MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(shell basename "$(shell dirname "$(MKFILE_PATH)")")

CHALL_NAME = $(CURRENT_DIR)
DOCKERHUB_ACCOUNT = adamdoupe
ALL_CONTENTS_FILES = $(shell find contents -type f)


.PHONY: run debug-shell build deploy run

all: build

run: 
	docker run --rm -p 127.0.0.1:31337:31337 -it $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME)

debug-shell:
	docker run --rm --security-opt seccomp:unconfined -it $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME) bash

build: compile Dockerfile $(ALL_CONTENTS_FILES)
	docker build . -t $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME)

deploy: build
	docker push $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME)

compile: contents/challenge libc.so.6

contents/challenge: $(CHALL_NAME)
	cp $(CHALL_NAME) contents/challenge

libc.so.6:
	docker run -i --rm $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME) bash -c 'echo "$$(file ./challenge)" | grep "32-bit"; if [ $$? -eq 0 ]; then cat /lib/i386-linux-gnu/libc.so.6; else cat /lib/x86_64-linux-gnu/libc.so.6; fi;' > libc.so.6

BUILD_GEN = $(shell docker create -v /build $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME))
BUILD = $(eval BUILD := $(BUILD_GEN))$(BUILD)
