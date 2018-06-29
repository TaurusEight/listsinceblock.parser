# Time-stamp: <2018-06-11 19:49:47 daniel>

#
# Dockerfile
#

# This is the Docker file associated with the project parseblock
# and the application 'block.parse'.
#
# Auther: Daniel Mendyke [archadious@gmail.com]
# https://github.com/TaurusEight/blockparse


FROM base/archlinux:latest
ADD . /parseblock
RUN pacman-db-upgrade
RUN pacman -Syyu --noconfirm
RUN pacman -S --noconfirm gcc boost make
RUN make -C /parseblock/src clean
RUN make -C /parseblock/src
