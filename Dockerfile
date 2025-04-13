FROM ubuntu:22.04

RUN apt update && apt install -y g++ make

WORKDIR /app

COPY . .

RUN g++ -o vaja1 Vaja1.cpp

CMD ["./vaja1", "0", "in.txt"]
