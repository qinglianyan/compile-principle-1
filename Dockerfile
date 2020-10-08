FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc token.c -o token
RUN chmod +x token