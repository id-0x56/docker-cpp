FROM debian:bullseye

ARG USERNAME=debian
ARG USER_UID=1000
ARG USER_GID=$USER_UID
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

ENV TZ=Europe/London
RUN apt update \
    && apt install -y tzdata \
    && ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone

RUN apt update \
    && apt install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

RUN apt update \
    && apt install -y build-essential cmake pkg-config gdb

USER $USERNAME



# docker builder prune -af \
#     && docker system prune -af \
#     && docker volume prune -f \
#     && docker image prune -af

# docker login
# docker build --no-cache -t 00x56/docker-cpp:latest .
# docker push 00x56/docker-cpp:latest

# docker run --rm --interactive --tty 00x56/docker-cpp /bin/bash
# docker exec --interactive --tty --user root 7809913082a3 /bin/bash
# docker exec --interactive --tty 7809913082a3 /bin/bash
