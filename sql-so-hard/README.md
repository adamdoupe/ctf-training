# `sql-so-hard` from HITCON CTF 2017 Quals

`sql-so-hard` is an excellent challenge from the [2017 HITCON CTF 2017 Quals][hitcon-quals-2017] written by [orange][orange-github].

The challenge text was (after a hint was released):

	Shell please
	http://localhost:31337/
	Hint: [Here][target] is the target. But how to make the check FAIL?

The goal is to steal the flag (located in this instance as `/flag`) remotely.

To run the challenge locally on your machine:

	docker run -p 127.0.0.1:31337:31337 -it adamdoupe/sql-so-hard

Once this completes you should be able to connect to the instance at `http://localhost:31337`

[hitcon-quals-2017]: https://ctftime.org/event/485/
[orange-github]: https://github.com/orangetw/My-CTF-Web-Challenges
[target]: https://node-postgres.com/announcements#2017-08-12-code-execution-vulnerability
