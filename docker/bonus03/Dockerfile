FROM ubuntu

MAINTAINER wide-aze

RUN apt-get update ; apt-get install -y build-essential vim emacs git apache2 libapache2-mod-php5 php5 mysql-server ; apt-get clean

ADD ./build_files/custbashrc /home/.custbashrc

CMD bash --rcfile /home/.custbashrc
