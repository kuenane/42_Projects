#doc: http://docs.docker.com/examples/running_ssh_service/

FROM ubuntu

MAINTAINER wide-aze

#install openssh
RUN apt-get update ; apt-get install -y openssh-server ; apt-get clean

#add ssh file config
ADD ./build_files/sshd_config /etc/ssh/

#create required dir
RUN mkdir /var/run/sshd

#create my sudo own user
RUN useradd -d /home/wide-aze -m -s /bin/bash wide-aze
RUN echo 'wide-aze:wide-aze' | chpasswd
RUN echo 'wide-aze ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers.d/wide-aze
RUN chmod 0440 /etc/sudoers.d/wide-aze
RUN echo 'root:screencast' | chpasswd
RUN sed -i 's/PermitRootLogin without-password/PermitRootLogin yes/' /etc/ssh/sshd_config

#ssh login fix (user was kicked off after login)
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

#enable profile visibility
RUN echo "export VISIBLE=now" >> /etc/profile

#add the id_rsa.pub key + chown/chmod
RUN mkdir -p /home/wide-aze/.ssh ; chown wide-aze /home/wide-aze/.ssh ; chmod 700 /home/wide-aze/.ssh
ADD ./build_files/id_rsa.pub /home/wide-aze/.ssh/authorized_keys
RUN chown wide-aze /home/wide-aze/.ssh/authorized_keys ; chmod 600 /home/wide-aze/.ssh/authorized_keys

#open port 42
EXPOSE 42

#launch ssh service
CMD ["/usr/sbin/sshd", "-D"]
