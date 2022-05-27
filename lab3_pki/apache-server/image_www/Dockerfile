FROM handsonsecurity/seed-server:apache-php

ARG WWWDIR=/var/www/tt2022

COPY ./index.html ./index_red.html $WWWDIR/
COPY ./tt2022_apache_ssl.conf /etc/apache2/sites-available
COPY ./certs/server_malicious_cert.crt ./certs/malicious_server.key  /certs/

RUN  chmod 400 /certs/malicious_server.key \
     && chmod 644 $WWWDIR/index.html \
     && chmod 644 $WWWDIR/index_red.html \
     && a2ensite tt2022_apache_ssl   

CMD  tail -f /dev/null

