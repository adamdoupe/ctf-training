# `poli_wars` from poliCTF 2017

`poli_wars` is an excellent challenge from the
[2017 poliCTF][polictf-2017].

You are given the [binary][binary]. The challange was `pwnable` worth 150 points. 

The goal is to write a repeatable exploit script to steal the flag
(located at `/challenge/flag`) remotely.

To run the challenge locally on your machine:

	docker run -p 127.0.0.1:31337:31337 -it adamdoupe/poli_wars

This will download the [docker image][docker-container] and run it
using docker. The challenge is running under [xinetd][xinetd-man] on
port 31337 in the container. The `-p` option maps the localhost's port
31337 to the docker container's port 31337. The 127.0.0.1 part is
optional (this restricts the port on your actual machine to only
listen for connections from localhost), however you are running
intentionally vulnerable software on your machine, so it's not a good
idea for it to be accessible to other machines.

You should then be able to access poli_wars like so:

	nc localhost 31337

To jump in and debug the program, you can use the following command
to get a bash shell

	docker run --security-opt seccomp:unconfined -it adamdoupe/poli_wars bash

[google-quals-2017]: https://ctftime.org/event/455
[quals-2016]: https://ctftime.org/event/320
[pctf-2017]: https://ctftime.org/event/439
[polictf-2017]: https://ctftime.org/event/425
[binary]: poli_wars
[docker-container]: https://hub.docker.com/r/adamdoupe/poli_wars/
[xinetd-man]: https://linux.die.net/man/8/xinetd
[adamd-homepage]: http://adamdoupe.com
[rop]: https://en.wikipedia.org/wiki/Return-oriented_programming
[babys-first-rop-32]: ../babys-first-rop-32/README.md
[baby-pivot]: ../baby-pivot/README.md
[format-your-pivot]: ../format-your-pivot/README.md
[one-byte-to-freedom]: ../one-byte-to-freedom/README.md
[libc]: libc.so.6
