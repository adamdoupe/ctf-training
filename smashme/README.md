
# `smashme` from 2017 DEFCON CTF Quals

`smashme` is an excellent challenge from the [2017 DEFCON CTF Quals][defcon-quals-2017].

In the original challenge, you are given the [binary][binary]. The
binary is the original one from the competition.

The goal is to write a repeatable exploit script to steal the flag
(located at `/challenge/flag`, although it should just be `flag` in
the current directory) remotely.

To run the challenge locally on your machine:

	docker run -p 127.0.0.1:31337:31337 -it adamdoupe/smashme

This will download the [docker image][docker-container] and run it
using docker. The challenge is running under [xinetd][xinetd-man] on
port 31337 in the container. The `-p` option maps the localhost's port
31337 to the docker container's port 31337. The 127.0.0.1 part is
optional (this restricts the port on your actual machine to only
listen for connections from localhost), however you are running
intentionally vulnerable software on your machine, so it's not a good
idea for it to be accessible to other machines.

You should then be able to access smashme like so:

	nc localhost 31337

To jump in and debug the program, you can use the following command
to get a bash shell

	docker run --security-opt seccomp:unconfined -it adamdoupe/smashme bash

[defcon-quals-2017]: https://ctftime.org/event/459
[pctf-2017]: https://ctftime.org/event/439
[binary]: smashme
[docker-container]: https://hub.docker.com/r/adamdoupe/smashme/
[xinetd-man]: https://linux.die.net/man/8/xinetd
