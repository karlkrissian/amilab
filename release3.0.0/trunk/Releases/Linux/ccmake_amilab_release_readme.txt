
set the wx-config to the one in /usr/bin to allow using the system configuration

libOSMesa.so not found

sudo ln -s /usr/lib64/libOSMesa.so.6 /usr/lib64/libOSMesa.so

another problem, don´t know why, it founds by default OpenGL library as /usr/lib64/libGL.so.1
instead of /usr/lib64/nvidia/libGL.so.1
setting it in cmake fixes the pb ...