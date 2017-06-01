CC_FLAGS = -static -fno-stack-protector


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

build: contents/challenge Dockerfile $(ALL_CONTENTS_FILES)
	docker build . -t $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME)

deploy: build
	docker push $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME)

compile: contents/challenge

contents/challenge: contents/$(CHALL_NAME).c
	docker run -i --rm -v /build --volumes-from=$(BUILD) $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME) bash -c "gcc $(CC_FLAGS) $(CHALL_NAME).c -o /build/$(CHALL_NAME)"; status=$$?; docker cp $(BUILD):/build/$(CHALL_NAME) .; docker rm -f -v $(BUILD); cp $(CHALL_NAME) contents/challenge; exit $$status

BUILD_GEN = $(shell docker create -v /build $(DOCKERHUB_ACCOUNT)/$(CHALL_NAME))
BUILD = $(eval BUILD := $(BUILD_GEN))$(BUILD)
