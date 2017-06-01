FROM adamdoupe/vuln-base:latest

COPY contents/ /challenge
RUN chmod +x challenge

WORKDIR /challenge

EXPOSE 31337
CMD ["/usr/sbin/xinetd", "-d", "-dontfork", "-f", "challenge.conf"]
