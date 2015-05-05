FROM codenvy/cpp
ENV CODENVY_APP_BIND_DIR /home/user/app
VOLUME ["/home/user/app"]
CMD cd /home/user/app && \
	 make clean &&\
    make all && \
    ./hello.exe &&\
    ./test_hash_map.exe &&\
    ./unordered_map.exe &&\
    ./timemap.exe

