FROM ubuntu

MAINTAINER wide-aze

EXPOSE 80

RUN apt-get update ; apt-get install -y nginx ; apt-get clean

ADD ./build_files/index.html /usr/share/nginx/html/

ADD ./build_files/custbashrc /home/.custbashrc

CMD bash --rcfile /home/.custbashrc
