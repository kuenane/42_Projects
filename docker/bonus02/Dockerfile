FROM ubuntu

MAINTAINER wide-aze

RUN apt-get update ; apt-get install -y build-essential emacs git ; apt-get clean

ADD ./build_files/custbashrc /home/.custbashrc

ADD ./build_files/dotemacs /home/.emacs

RUN git clone https://github.com/wide-aze/wide-aze.github.io.git

CMD bash --rcfile /home/.custbashrc
