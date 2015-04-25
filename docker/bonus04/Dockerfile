FROM ubuntu

MAINTAINER wide-aze

RUN apt-get update ; apt-get install -y build-essential vim emacs git ruby ruby-dev postgresql nginx ; apt-get clean

ADD ./build_files/custbashrc /home/.custbashrc

CMD bash --rcfile /home/.custbashrc
