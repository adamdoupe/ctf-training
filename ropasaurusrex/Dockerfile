FROM adamdoupe/vuln-base:latest

COPY contents/ /challenge
RUN chmod +x challenge

WORKDIR /challenge

EXPOSE 31337
CMD ["/bin/bash", "run_xinetd.sh"]
