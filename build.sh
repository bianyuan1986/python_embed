#!/bin/bash


#[root@VM_14_30_centos ~/python_embed]# /usr/bin/python2.7-config --cflags
#-I/usr/include/python2.7 -I/usr/include/python2.7 -fno-strict-aliasing -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -D_GNU_SOURCE -fPIC -fwrapv -DNDEBUG -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -D_GNU_SOURCE -fPIC -fwrapv
#[root@VM_14_30_centos ~/python_embed]# /usr/bin/python2.7-config --ldflags 
#-lpthread -ldl -lutil -lm -lpython2.7 -Xlinker -export-dynamic

gcc main.c -I/usr/include/python2.7 -I/usr/include/python2.7 -fno-strict-aliasing -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -D_GNU_SOURCE -fPIC -fwrapv -DNDEBUG -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic -D_GNU_SOURCE -fPIC -fwrapv -lpthread -ldl -lutil -lm -lpython2.7 -Xlinker -export-dynamic -g -o main

#PYTHONPATH=. ./main multiply multiply 3 4
