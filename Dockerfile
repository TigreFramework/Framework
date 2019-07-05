FROM httpd:2.4

RUN apt-get update && apt-get install -y valgrind gcc g++ cmake inotify-tools

RUN echo "@.idea" >> /tmp/lixo && \
    echo "@.git" >> /tmp/lixo && \
    echo "@cmake-build-debug" >> /tmp/lixo

RUN echo "mkdir -p /usr/source/cmake-build-debug" >> /usr/local/bin/auto-build && \
    echo "cd /usr/source/cmake-build-debug" >> /usr/local/bin/auto-build && \
    echo "cmake .." >> /usr/local/bin/auto-build && \
    echo "make -j4" >> /usr/local/bin/auto-build && \
    echo "while true; do" >> /usr/local/bin/auto-build && \
    echo "inotifywait -e modify,create,delete -r --fromfile /tmp/lixo /usr/source/ && make" >> /usr/local/bin/auto-build && \
    #echo "inotifywait -e modify,create,delete -r /usr/source/ && make" >> /usr/local/bin/auto-build && \
    echo "done" >> /usr/local/bin/auto-build && \
    chmod 777 /usr/local/bin/auto-build

RUN echo "rm -f /usr/local/apache2/logs/httpd.pid" >> /usr/local/bin/httpd-foreground && \
    echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:/usr/local/apache2/htdocs/lib/" >> /usr/local/bin/httpd-foreground && \
    echo "echo 1" >> /usr/local/bin/httpd-foreground && \
    echo "auto-build &" >> /usr/local/bin/httpd-foreground && \
    echo "echo 2" >> /usr/local/bin/httpd-foreground && \
    echo "httpd -DFOREGROUND" >> /usr/local/bin/httpd-foreground && \
    chmod 777 /usr/local/bin/httpd-foreground


COPY ./httpd.conf /usr/local/apache2/conf/httpd.conf